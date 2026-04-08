#ifndef _PROS_INTAKE_CONTROL_H_
#define _PROS_INTAKE_CONTROL_H_

#include "main.h"
#include "pros/motors.hpp"

//First stage functions
extern void grab();
extern void extake();
extern void lowGoal();

//Arm functions
extern void score();
extern void midScore();

extern void rest();

#endif
