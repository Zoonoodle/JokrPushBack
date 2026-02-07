#ifndef _PROS_INTAKE_CONTROL_H_
#define _PROS_INTAKE_CONTROL_H_

#include "main.h"
#include "pros/motors.hpp"

// === ARM POSITIONS (centidegrees) ===
extern const int LOAD_POS;
extern const int SCORE_POS;

// === ARM PD GAINS (tune these in intakeControl.cpp) ===
extern double armKp;
extern double armKd;

// === ARM CONTROL ===
extern void setArmLoad();
extern void setArmScore();
extern void setArmPosition(int position);
extern int  getArmTarget();
extern int  getArmPosition();

// Background PD task — call once in initialize()
extern void armPDTask();

// === INTAKE CONTROL ===
extern void intakeForward();
extern void intakeReverse();
extern void intakeStop();
extern void intakeForwardSlow(int speed);

// === INTAKE UNJAM ===
// True while the unjam routine is actively reversing the intake.
// Check this before writing to the intake motor so the unjam isn't overridden.
extern bool intakeUnjamming;
// Background task — call once in initialize()
extern void intakeUnjamTask();

#endif
