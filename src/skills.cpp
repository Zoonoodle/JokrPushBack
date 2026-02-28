#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

// TODO: All skills routines need to be rewritten for new robot hardware
// New robot has: single intake motor, arm motor with PID, 5 pneumatics (fourBar, scraper, intakeLift, odomLift, hoard)

// void skillsOwen() {
//     // TODO: Rewrite for new robot
// }

void skills() {
    hoard.set_value(true);
    pros::Task unjamTask(intakeUnjamTask);
    fourBar.set_value(false);
    moveF(481, true, true, 65, 0, 1100);
    chassis.turnToHeading(92, 600);
    
    intake.move(127);
pros::delay(100);
scraper.set_value(true);

    chassis.moveToPoint(8, chassis.getPose().y, 1600, {.maxSpeed = 45});
    chassis.waitUntilDone();
    left_motors.move(30);
    right_motors.move(30);
    pros::delay(1300);
//    left_motors.move(45);
//    right_motors.move(45);
// pros::delay(1300);

    chassis.moveToPoint(0,chassis.getPose().y, 700, {.forwards = false});
    chassis.turnToHeading(180, 500);
    scraper.set_value(false);
    chassis.waitUntilDone();
    moveB(145, false, true, 60, 0, 700);
    chassis.turnToHeading(271, 550);
    chassis.moveToPoint(-97.5, chassis.getPose().y-.25, 3000, {.maxSpeed = 95});
    pros::delay(400);
    arm.move(0);
    // moveF(655, true, true, 90, 0, 3000);
    chassis.turnToHeading(0, 600);
    chassis.waitUntilDone();
    moveF(495, false, false, 75,0, 800);
    fourBar.set_value(true);
    chassis.turnToHeading(270, 550);
    chassis.moveToPoint(chassis.getPose().x+13, chassis.getPose().y, 1200, {.forwards = false});

intake.move(127);
    chassis.waitUntil(6);
    hoard.set_value(false);

    pros::delay(300);
arm.move(90);
pros::delay(300);
intake.move(-127);
pros::delay(500);
arm.move(-127);
scraper.set_value(true);
chassis.moveToPoint(-114, chassis.getPose().y-.5, 2000, {.maxSpeed = 50, .minSpeed = 40});
hoard.set_value(true);
pros::delay(300);
fourBar.set_value(false);
intake.move(127);
arm.move(0);


chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(1600);

chassis.moveToPoint(-86, chassis.getPose().y, 1500, {.forwards = false});
pros::delay(100);
fourBar.set_value(true);

chassis.waitUntil(19);
hoard.set_value(false);
pros::delay(800);
arm.move(90);
pros::delay(400);
intake.move(-127);
pros::delay(400);
arm.move(-127);

scraper.set_value(false);
pros::delay(400);
arm.move(0);

chassis.moveToPoint(chassis.getPose().x -9, chassis.getPose().y, 700);

chassis.turnToHeading(180, 600);
intake.move(0);
fourBar.set_value(false);
chassis.waitUntilDone();

moveF(482, true, true, 80, 0, 2600);
chassis.turnToHeading(272, 500);
scraper.set_value(true);
intake.move(127);
hoard.set_value(true);

chassis.moveToPoint(chassis.getPose().x -18, chassis.getPose().y+.25, 1500, {.maxSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(1600);
left_motors.move(-50);
right_motors.move(-50);
    pros::delay(300);

chassis.moveToPoint(chassis.getPose().x + 8, chassis.getPose().y, 700);
chassis.turnToHeading(0, 500);
scraper.set_value(false);
chassis.waitUntilDone();

moveB(140, false, true, 60, 0, 700);
chassis.turnToHeading(91, 500);
chassis.moveToPoint(-12, chassis.getPose().y, 3000, {.maxSpeed = 90}); 
chassis.turnToHeading(180, 500);
intake.move(0);
chassis.waitUntilDone();
moveF(465, false, false, 70,0, 1000);
fourBar.set_value(true);
chassis.turnToHeading(90, 450);
chassis.waitUntilDone();
intake.move(127);
chassis.moveToPoint(chassis.getPose().x-14, chassis.getPose().y, 1200, {.forwards = false});
pros::delay(100);
fourBar.set_value(true);

chassis.waitUntil(9);
hoard.set_value(false);
pros::delay(400);
arm.move(90);
pros::delay(300);
intake.move(-127);
pros::delay(400);
arm.move(-127);
chassis.moveToPoint(chassis.getPose().x + 28, chassis.getPose().y, 2000, {.maxSpeed = 50, .minSpeed = 40});
scraper.set_value(true);
pros::delay(400);
fourBar.set_value(false);
intake.move(127);
arm.move(0);
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(1400);
// chassis.turnToHeading(10, 200);
// 	chassis.turnToHeading(-10, 200);
// 	chassis.turnToHeading(10, 200);
// 	chassis.turnToHeading(-10, 200);
// 	chassis.turnToHeading(10, 200);
// 	chassis.turnToHeading(-10, 200);
chassis.moveToPoint(chassis.getPose().x-29, chassis.getPose().y, 1500, {.forwards = false, .maxSpeed= 90});
pros::delay(100); 
fourBar.set_value(true);

chassis.waitUntil(19);
hoard.set_value(false);
pros::delay(600);
arm.move(100);
pros::delay(400);
intake.move(-127);
pros::delay(400);
arm.move(-127);

scraper.set_value(false);
// chassis.moveToPoint(chassis.getPose().x+15, chassis.getPose().y, 800);
// pros::delay(400);
// arm.move(0);
// chassis.turnToHeading(0, 550);;
// chassis.waitUntilDone();
// intake.move(0);
// moveB(1180, true, false, 75, 0, 1000);
// chassis.turnToHeading(90, 500);
// chassis.waitUntilDone();
// moveF(138, true, true, 70, 0, 1000);
// fourBar.set_value(false);
// wing.set_value(false);
// intake.move(-127);
// chassis.turnToHeading(20, 500);
// chassis.waitUntilDone();
// left_motors.move(85);
// right_motors.move(85);
// pros::delay(900);
// left_motors.move(0);
// right_motors.move(0);
   // moveB(141,true, bool decreasing, int maxSpeed, int minSpeed, int timeOutMs)
}

void riskySkills() {
    // TODO: Rewrite for new robot
}
