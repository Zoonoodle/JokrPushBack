#include "intakeControl.h"
#include "pros/rtos.hpp"
#include "robotConfigs.h"

void grab(){
    pto.set_value(true);
    sharedMotors.move(-127);
}
void extake(){
    pto.set_value(true);
    sharedMotors.move(120);
}
void lowGoal(){
    pto.set_value(true);
    sharedMotors.move(40);
}

void score(){
    pto.set_value(false);
    sharedMotors.move(-127);
    pros::delay(450);
    sharedMotors.move(100);
    pros::delay(200);
    rest();
}
void slowScore(){
    pto.set_value(false);
    sharedMotors.move(-50);
    pros::delay(700);
    sharedMotors.move(100);
    pros::delay(200);
    rest();
}

void rest(){
    sharedMotors.move(0);

}