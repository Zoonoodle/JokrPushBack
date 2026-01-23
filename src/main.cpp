#include "main.h"
#include "lemlib/api.hpp"
#include "autons.h"
#include "pros/optical.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"
// Global screen task pointer
pros::Task* screen_task = nullptr;



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    
    
    // Suspend doublePark task initially - will be resumed when button pressed

	// pros::Task  unjamTask([] {
	// 	while(unjamEnabled) {
	// 	unjam();
	// 	pros::delay(10);
	// 	}});
    // Create screen display task as a global task that persists
    screen_task = new pros::Task([=]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %.2f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %.2f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %.2f", chassis.getPose().theta); // heading
            // delay to save resources
			pros::lcd::print(3, "Front: %.2f", (float) frontDist.get());
			pros::lcd::print(4, "Back: %.2f", (float) backDist.get());
			pros::lcd::print(5, "Unjam: %.2f", (float) intakeBottom.get_actual_velocity());
			pros::lcd::print(6, "Unjam Target: %.2f", (float) intakeBottom.get_target_velocity());
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    // Screen task continues running even when disabled
	hoard.set_value(true);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the	 robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// wings.set_value(true);
	topOptical.set_led_pwm(65);
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	// unjam_task->resume();  // Resume unjam task for autonomous
// elimsMidRush();
leftSide4ball();	// SigSawp();
	// sevenBall();
	// skillsOwen();
	// SigSawp15Ball();
	// antiVitalityAuto();
	// elimsMidRush();
	// //sevenBall();
	// odomLift.set_value(true);
	// noOdomChassis.moveToPoint(1, 26, 2000, {.maxSpeed = 90, .minSpeed = 90, .earlyExitRange = 5});
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// left_motors.move(75);
	// right_motors.move(75);
	// pros::delay(1000);
	// left_motors.move(0);
	// right_motors.move(0);
	bool isFirstTime = true;
	unjamEnabled = true;

	
gatePressed = false;
	static bool doubleParkReady = false;
	static bool doinkPressed = false;
	static bool parkPressed = false;
	static bool gatePressed = false;
	static bool wingsPressed = false;
	static int lastGateToggleTime = 0;
	
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	// odomLift.set_value(true);
	while (true) {
		int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with arcade controls
        chassis.arcade(leftY, // throttle
                       rightX * 0.65, // steer (reduced sensitivity)
                       true, // enable drive curves for smoother control
                       0.7 // slightly prioritize steering
		);



		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			intakeBottom.move(127);
			intakeTop.move(-127);
			hoard.set_value(false);

		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			intakeBottom.move(127);
			intakeTop.move(-100);
			hoard.set_value(true);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			if(isFirstTime) {
				isFirstTime = false;
				unload();
			}
			intakeBottom.move(127);
			intakeTop.move(127);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
			slowMiddleScore();
		}
		
	
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			intakeBottom.move(-127);
			intakeTop.move(127);
		}
		else {
			intakeBottom.move(0);
			intakeTop.move(0);
		}

		// Wings up by default, down while R2 is held
		wings.set_value(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
			
		// Handle wings toggle
		
		
		// Handle doink toggle
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			doinkPressed = !doinkPressed;
			doink.set_value(doinkPressed);
		}

		

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
			doubleParkReady = false;
		}
		pros::delay(20);          // Run for 20 ms then update
	}
}