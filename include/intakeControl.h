#ifndef _PROS_INTAKE_CONTROL_H_
#define _PROS_INTAKE_CONTROL_H_

#include "main.h"
#include "lemlib/api.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
extern void slowExtake();
extern bool gatePressed;

extern pros::Task* doublePark;
extern void load();
extern void unload();
extern void middleScore();
extern void rest();
extern bool firstStageCounted(int count, int timeoutMs = 5000);
extern bool secondStageCounted(int count, int timeoutMs = 5000);
extern bool noBallsLeft();
extern bool empty();
extern bool isDone;
extern void unjam();
extern void middleGetBall();
extern pros::Task* unjam_task;
extern bool intakeOn;
extern bool unjamEnabled;
extern void extake();
extern void slowUnload();
extern void slowMiddleScore();
// Unjam control functions
extern void enableUnjam();
extern void disableUnjam();
extern bool isUnjamEnabled();

// Autonomous helper functions for loading balls
extern bool loadBallsAuto(int ballCount, int timeoutMs = 5000);
extern pros::Task* loadBallsAsync(int ballCount, int timeoutMs = 5000);

// Autonomous helper functions for scoring balls
extern bool scoreBallsAuto(int ballCount, int timeoutMs = 5000);
extern pros::Task* scoreBallsAsync(int ballCount, int timeoutMs = 5000);
extern bool middleScoreAuto(int ballCount, int timeoutMs = 5000);
extern pros::Task* middleScoreAsync(int ballCount, int timeoutMs = 5000);

// Index/score control function - runs intake until specified number of balls scored
extern void stopUntilScored(int ballsToScore);

// Color detection functions - stops intake when specific color ball is detected
extern void stopWhenRed();
extern pros::Task* stopWhenBlue();  // Returns task that runs asynchronously
#endif