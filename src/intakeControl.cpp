#include "intakeControl.h"
#include "robotConfigs.h"

// =====================================================
// ARM PD CONTROLLER — TUNING SECTION
// All tunables are here at the top. Positions are in
// centidegrees (rotation sensor units: 1 degree = 100).
// =====================================================

// --- Arm Positions (centidegrees) ---
// LOAD_POS: default resting position (0 degrees)
// SCORE_POS: where the arm scores — CALIBRATE THIS
const int LOAD_POS  = 0;
const int SCORE_POS = 6000;  // ~60 degrees — adjust after testing

// --- PD Gains ---
// kP: how aggressively the arm corrects error (start ~0.5, increase if sluggish)
// kD: dampening to prevent overshoot (start ~0.3, increase if oscillating)
double armKp = 0.02;
double armKd = 0.1;

// --- Misc ---
// Max motor output (0-127). Lower = safer while tuning.
const int ARM_MAX_OUTPUT = 127;

// =====================================================
// STATE
// =====================================================

// The target position the PD loop drives toward.
// Set this from opcontrol or auton to move the arm.
int armTarget = LOAD_POS;

// =====================================================
// PUBLIC FUNCTIONS
// =====================================================

void setArmLoad() {
    armTarget = LOAD_POS;
}

void setArmScore() {
    armTarget = SCORE_POS;
}

void setArmPosition(int position) {
    armTarget = position;
}

int getArmTarget() {
    return armTarget;
}

int getArmPosition() {
    return armRot.get_position();
}

// =====================================================
// PD CONTROL TASK — runs in background forever
// =====================================================

void armPDTask() {
    double prevError = 0;

    while (true) {
        double current = armRot.get_position();
        double error   = armTarget - current;
        double deriv   = error - prevError;
        prevError      = error;

        double output = (armKp * error) + (armKd * deriv);

        // Clamp to motor range
        if (output > ARM_MAX_OUTPUT)  output = ARM_MAX_OUTPUT;
        if (output < -ARM_MAX_OUTPUT) output = -ARM_MAX_OUTPUT;

        arm.move(static_cast<int>(output));

        pros::delay(10);
    }
}

// =====================================================
// INTAKE HELPERS (unchanged)
// =====================================================

void intakeForward() {
    intake.move(127);
}

void intakeReverse() {
    intake.move(-127);
}

void intakeStop() {
    intake.move(0);
}

void intakeForwardSlow(int speed) {
    intake.move(speed);
}

// =====================================================
// INTAKE UNJAM TASK — runs in background forever
// =====================================================

bool intakeUnjamming = false;

void intakeUnjamTask() {
    int stallCount = 0;
    const int STALL_CHECKS = 4; // 4 * 50 ms = 200 ms of stall before unjam

    while (true) {
        double voltage  = intake.get_voltage();
        double velocity = intake.get_actual_velocity();

        // Motor is commanded forward but not spinning
        if (voltage > 3000 && std::abs(velocity) < 10) {
            stallCount++;
        } else {
            stallCount = 0;
        }

        if (stallCount >= STALL_CHECKS) {
            intakeUnjamming = true;
            intake.move(-127);       // reverse briefly
            pros::delay(100);
            intake.move(127);        // resume forward
            intakeUnjamming = false;
            stallCount = 0;
        }

        pros::delay(50);
    }
}
