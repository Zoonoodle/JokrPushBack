#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "movement.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

// TODO: All autonomous routines need to be rewritten for new robot hardware
// New robot has: single intake motor, arm motor with PID, 5 pneumatics (fourBar, scraper, intakeLift, odomLift, hoard)
void SigSawp() {
    moveF(474, true, true, 75, 0, 1000);
    chassis.turnToHeading(90, 600);
    
    intake.move(127);
pros::delay(100);
scraper.set_value(true);
    chassis.moveToPoint(9, chassis.getPose().y, 1300, {.maxSpeed = 60, .minSpeed = 50});
    chassis.waitUntilDone();
    left_motors.move(35);
    right_motors.move(35);
    fourBar.set_value(true);
    pros::delay(300);



    chassis.moveToPoint(-20,chassis.getPose().y, 1600, {.forwards = false});
    chassis.waitUntil(19);
    hoard.set_value(false);
    chassis.waitUntil(4);
    arm.move(127);
    chassis.waitUntilDone();
    scraper.set_value(false);


    pros::delay(200);

    chassis.moveToPoint(chassis.getPose().x + 10,chassis.getPose().y, 650);
    intake.move(-127);
    arm.move(-127);

    pros::delay(650);
    arm.move(-10);
   
    chassis.turnToHeading(215, 500);
    chassis.moveToPoint(-27, 9, 1500, {.maxSpeed =65});
    intake.move(127);
    hoard.set_value(true);


    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 550);
    chassis.moveToPoint(-27, -34, 800, {.earlyExitRange = 10});
    chassis.moveToPoint(-27, -46, 1300, {.maxSpeed = 50});
    chassis.waitUntil(9);
    scraper.set_value(true);
    

intake.move(127);

chassis.turnToHeading(140,  500);
scraper.set_value(false);
chassis.moveToPoint(-5, -71, 800);
chassis.turnToHeading(90, 400);
intake.move(-127);
pros::delay(100);
intake.move(127);
chassis.moveToPoint(-20.5, -71, 1200, {.forwards = false});
chassis.waitUntil(5);
hoard.set_value(false);
intake.move(127);
pros::delay(300);

arm.move(127);
chassis.waitUntilDone();
pros::delay(300);
intake.move(-127);
arm.move(-127);


chassis.moveToPoint(10, -71.5, 1800, {.maxSpeed = 60, .minSpeed = 50});
scraper.set_value(true);
pros::delay(200);
intake.move(127);
arm.move(-10);
intake.move(127);

hoard.set_value(true);

chassis.waitUntilDone();
left_motors.move(40);
right_motors.move(40);
pros::delay(300);
moveF(540, false, false, 75, 0, 800);
chassis.turnToHeading(137, 500);
chassis.moveToPoint(-34.87, -34.38,2000, {.forwards = false, .maxSpeed=85, .minSpeed=70});
fourBar.set_value(false);

chassis.waitUntil(46);
hoard.set_value(false);
pros::delay(100);
arm.move(100);


}

void PIDtune() {
    // chassis.turnToHeading(90, 500);
    // chassis.turnToHeading(0, 600);
    // chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 24, 1000);
    chassis.moveToPoint(0, 0, 1000, {.forwards = false});
}

void elimsMidRush() {
    // TODO: Rewrite for new robot
}

void sevenBall() {
    // TODO: Rewrite for new robot
}

void powerBeansAuto() {
    // TODO: Rewrite for new robot
}

void SigSawp15Ball() {
    // TODO: Rewrite for new robot
}

void lateMidSawp() {
    // TODO: Rewrite for new robot
}

void antiVitalityAuto() {
    // TODO: Rewrite for new robot
}



void leftSideNineBall() {
    // TODO: Rewrite for new robot
}

void leftSide4ball() {
    // TODO: Rewrite for new robot
}
