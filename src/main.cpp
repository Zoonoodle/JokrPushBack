#include "main.h"
#include "lemlib/api.hpp"
#include "autons.h"
#include "liblvgl/core/lv_obj_class.h"
#include "movement.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
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
	// arm.tare_position(); // zero the arm IME for armTo() position control
	scraper.set_value(true);
	// wing.s et_value(true);
	// hoard.set_value(false);
	// fourBar.set_value(true);
    chassis.calibrate();// calibrate sensors


    // Unjam task disabled — conflicts with PTO sharedMotors control
    // pros::Task unjamTask(intakeUnjamTask);

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
			pros::lcd::print(4, "left: %.2f", (float) leftDist.get());
			pros::lcd::print(4, "right: %.2f", (float) rightDist.get());
			// pros::lcd::print(5, "Arm IME: %.2f", (float) arm.get_position()); // degrees from motor encoder
			pros::lcd::print(6, "Intake Vel: %.2f", (float) intake.get_actual_velocity());
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
	scraper.set_value(true);
    // Screen task continues running even when disabled
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
void competition_initialize() {
	// fourBar.set_value(true);
	// hoard.set_value(true);
}

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
	chassis.moveToPoint(0, 24, 1000);
chassis.moveToPoint(0, 0, 1000, {.forwards = false});
	// fourBallRight();
	// sixBallRight();
	// riskySkills();
	// SigSawp();
	//High54();
	// antiVitalityAuto();
	// chassis.moveToPoint(0, 61, 5000, {.maxSpeed = 50, .minSpeed = 50});
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	//  elimsMidRush();
// chassis.turnToHeading(180, 1000);
// chassis.waitUntilDone();
// chassis.turnToHeading(0, 1000);
// chassis.waitUntilDone();
	// leftSide4ball();
	// intake.move(127);
	// driveExpo(75, 5000, 6000);
	// pros::delay(500);
	// intake.move(0);
		// SigSawp();
		// SigSawp15Ball();

		/*
		void armTo(double targetDeg, int maxSpeed = 127, int timeOutMs = 1000, int settleMs = 100);
		
		572 pos full score, 
		215 = halfway for 2 balls
		*/
		// armTo(250, 70, 1500, 300);
		// riskySkills();
		// 
	// elimsMidRush();
// PIDtune();
	// moveF(300, true, true, 70, 0, 1000);
	// skills();
	// chassis.moveToPoint(0, 5, 1000);
	// Low54();
	// 
	// PIDtune();
	// TODO: Update autonomous routines for new robot
	// leftSide4ball();
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
	static int fourBarState = 1; // 0 = DOWN (intakeLift), 1 = UP (fourBar false), 2 = NEUTRAL (fourBar true)
	static bool scraperPressed = false;
	static bool l1WasHeld = false;
	double ptoPressed = false;

	// Non-blocking L1 release state machine
	// 0 = idle, 1 = motors reversing (wait 300ms), 2 = PTO shifted (wait 100ms)
	int l1ReleaseState = 0;
	uint32_t l1ReleaseTimer = 0;
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	sharedMotors.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	// PTO state machine: shared motors power intake OR arm via pneumatic shift
	// // pto false = arm mode, pto true = intake mode
	// enum PTOState { PTO_INTAKE, PTO_ARM_ENGAGING, PTO_ARM_UP, PTO_ARM_RETRACTING };
	// PTOState ptoState = PTO_INTAKE;
	// uint32_t ptoTimer = 0;
	pto.set_value(true); // start in intake mode

	while (true) {
		// === DRIVETRAIN ===
		int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		chassis.arcade(leftY, rightX * 0.679, true, 0.7);

bool l1Held = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1);

// Handle L1 release sequence non-blocking
if (l1ReleaseState == 1 && pros::millis() - l1ReleaseTimer >= 300) {
	pto.set_value(true);
	l1ReleaseTimer = pros::millis();
	l1ReleaseState = 2;
}
else if (l1ReleaseState == 2 && pros::millis() - l1ReleaseTimer >= 100) {
	sharedMotors.move(0);
	l1ReleaseState = 0;
}

if (l1ReleaseState == 0) {
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		hoard.set_value(false);
		grab();
		l1WasHeld = false;
	}
	else if (l1Held) {
		if (!l1WasHeld) {
			// first press — shift PTO then ease motors in
			l1WasHeld = true;
			hoard.set_value(true);
			pto.set_value(false);
			sharedMotors.move(-127);
		} else {
			sharedMotors.move(-127);
		}
	}
	else if (!l1Held && l1WasHeld) {
		// L1 just released — start non-blocking retract sequence
		sharedMotors.move(127);
		l1ReleaseTimer = pros::millis();
		l1ReleaseState = 1;
		l1WasHeld = false;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		extake();
	}
	else {
		rest();
	}
}





		// === PNEUMATIC TOGGLES ===
		if (fourBarState == 2) {
			wing.set_value(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
		} else {
			wing.set_value(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			scraperPressed = !scraperPressed;
			scraper.set_value(scraperPressed);
		}

		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			fourBarState = (fourBarState + 1) % 3;
			if (fourBarState == 0) {
				// DOWN: intakeLift engages
				intakeLift.set_value(true);
				fourBar.set_value(false);
			} else if (fourBarState == 1) {
				// UP: intakeLift off, fourBar false
				intakeLift.set_value(false);
				fourBar.set_value(false);
			} else {
				// NEUTRAL: intakeLift off, fourBar true
				intakeLift.set_value(false);
				fourBar.set_value(true);
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
		
			ptoPressed = !ptoPressed;
			pto.set_value(ptoPressed);
		}

		pros::delay(20);
	}
}