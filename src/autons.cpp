#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

void PIDtune() {
    chassis.moveToPoint(0, 24, 1000);
    chassis.moveToPoint(0, 0, 1000, {.forwards = false});
}

void elimsRed() {
    load();

    chassis.moveToPoint(-11, 31.5, 1500, {.maxSpeed = 110, .earlyExitRange = 2});

    chassis.turnToHeading(-133, 400);
    chassis.moveToPoint(4.88, 36, 1200, {.forwards = false, .maxSpeed = 70, .earlyExitRange = 5});
    chassis.turnToHeading(-138, 550);
    
    middleScore();




    
}
void sigSAWP() {
chassis.setPose(0,0,0);
chassis.moveToPoint(0,12,1000, {.maxSpeed = 100});
chassis.turnToHeading(90, 500);
chassis.moveToPoint(-18, chassis.getPose().y, 1000);
load();
doink.set_value(true);
chassis.waitUntilDone();
chassis.moveToPoint(-47, chassis.getPose().y, 1000, {.forwards = false});
chassis.waitUntil(chassis.getPose().x < -46);
unload();
pros::delay(750);
chassis.moveToPoint(chassis.getPose().x + 5, chassis.getPose().y, 250, {.minSpeed = 50});
chassis.swingToPoint(-45, 5, lemlib::DriveSide::RIGHT, 500);
chassis.moveToPoint(-45, 5, 750);
load();
chassis.turnToHeading(180, 200);
chassis.moveToPoint(chassis.getPose().x, -16, 1000);
chassis.turnToHeading(135, 450);
chassis.moveToPoint(-58, -4, 1000);
chassis.turnToHeading(90, 450);
}