#include "main.h"
#include "lemlib/api.hpp"
#include "autons.h"
#include "movement.h"
#include "pros/misc.h"
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
    armRot.reset(); 
	// zero the arm rotation sensor
    chassis.calibrate();// calibrate sensors
	

    // Start intake unjam background task
    pros::Task unjamTask(intakeUnjamTask);

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
			pros::lcd::print(5, "Arm Pos: %.2f", (float) armRot.get_position() / 100.0); // degrees
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
	fourBar.set_value(true);
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
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	leftSide4ball();
	// SigSawp();
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
enum ArmState { ARM_IDLE, ARM_PRIMING, ARM_UP, ARM_RETRACTING };
void opcontrol() {

	// moveF(300, true, true, 70, 0, 1000);
	// Pneumatic toggle states
	static bool fourBarPressed = false;
	static bool scraperPressed = false;
	static bool intakeLiftPressed = false;
	static bool hoardPressed = false;

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	while (true) {
		// === DRIVETRAIN ===
		int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		chassis.arcade(leftY, rightX * 0.65, true, 0.7);

		// === INTAKE CONTROL ===
		// Skip writing to the intake motor while the unjam routine is active
		if (!intakeUnjamming) {
			if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
				intake.move(127);
				hoard.set_value(true);
			} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
				intake.move(-127);
			} else {
				intake.move(0);
			}
		}

		// === ARM CONTROL (non-blocking) ===
		static ArmState armState = ARM_IDLE;
		static uint32_t armTimer = 0;

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			if (armState != ARM_PRIMING && armState != ARM_UP) {
				hoard.set_value(false);
				intake.move(127);
				pros::delay(50);
				armTimer = pros::millis();
				armState = ARM_PRIMING;
			} else if (armState == ARM_PRIMING && pros::millis() - armTimer >= 50) {
				arm.move(127);
				armState = ARM_UP;
			} else if (armState == ARM_UP) {
				arm.move(127);
			}
		} else {
			if (armState == ARM_UP || armState == ARM_PRIMING) {
				arm.move(-127);
				armTimer = pros::millis();
				armState = ARM_RETRACTING;
			} else if (armState == ARM_RETRACTING) {
				if (pros::millis() - armTimer >= 350) {
					arm.move(0);
					armState = ARM_IDLE;
				}
			} else {
				arm.move(0);
			}
		}

		// === PNEUMATIC TOGGLES ===
		// A: Toggle fourBar
		// Wings up by default, down while R2 is held
		wing.set_value(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));


		// B: Toggle scraper
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			scraperPressed = !scraperPressed;
			scraper.set_value(scraperPressed);
		}

		// X: Toggle intake lift
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			fourBarPressed = !fourBarPressed;
			fourBar.set_value((fourBarPressed));
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			fourBarPressed = !fourBarPressed;
			fourBar.set_value((fourBarPressed));
		}
		// Y: Toggle hoard
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
			hoardPressed = !hoardPressed;
			hoard.set_value(hoardPressed);
		}

		pros::delay(20);
	}
}