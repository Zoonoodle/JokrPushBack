#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "movement.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"
#include <ios>

// TODO: All autonomous routines need to be rewritten for new robot hardware
// New robot has: single intake motor, arm motor with PID, 5 pneumatics (fourBar, scraper, intakeLift, odomLift, hoard)
void SigSawp() {
    pros::Task unjamTask(intakeUnjamTask);
    fourBar.set_value(true);
    moveF(474, true, true, 75, 0, 1000);
    chassis.turnToHeading(90, 600);
    
    intake.move(127);
pros::delay(100);
scraper.set_value(true);
    chassis.moveToPoint(10, chassis.getPose().y, 1200, {.maxSpeed = 60, .minSpeed = 55});
    chassis.waitUntilDone();
   


    chassis.moveToPoint(-22,chassis.getPose().y, 1600, {.forwards = false});
    chassis.waitUntil(19);
    hoard.set_value(false);
    
    pros::delay(200);
arm.move(127);

    chassis.waitUntilDone();
    scraper.set_value(false);
    intake.move(-127);
    pros::delay(300);
   

    chassis.moveToPoint(chassis.getPose().x + 6,chassis.getPose().y, 500);
    

    pros::delay(300);
    arm.move(-127);
    
    intake.move(127);
   
    chassis.turnToHeading(217, 500);
    chassis.moveToPoint(-26, 14, 1000, {.maxSpeed =85});
    arm.move(-10);


    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 250);
    chassis.moveToPoint(-27, -34, 800, {.earlyExitRange = 10});
    pros::delay(200);
    intake.move(-80);
    pros::delay(100);
    intake.move(127);
    chassis.moveToPoint(-27, -38, 1300, {.maxSpeed = 60});
    chassis.waitUntil(4);
    scraper.set_value(true);
    

intake.move(127);

chassis.turnToHeading(144,  400);
scraper.set_value(false);
chassis.moveToPoint(-6, -68.5, 800);
chassis.turnToHeading(90, 350);
scraper.set_value(true);
intake.move(127);
chassis.moveToPoint(-23, -69.5, 1500, {.forwards = false});
chassis.waitUntil(5);
hoard.set_value(false);
intake.move(127);
pros::delay(200);
scraper.set_value(true);
arm.move(127);


chassis.waitUntilDone();
intake.move(-127);
left_motors.move(0);
right_motors.move(0);
pros::delay(300);
arm.move(-127);

chassis.moveToPoint(-8, -69, 700, {.maxSpeed = 80, .minSpeed = 70});
chassis.moveToPoint(11, -69   , 1300, {.maxSpeed = 55, .minSpeed = 50});
intake.move(127);
chassis.waitUntilDone();
pros::delay(250);
left_motors.move(35);
right_motors.move(35);
intake.move(127);

hoard.set_value(true);



moveF(470, false, false, 90, 40, 500);
chassis.turnToHeading(140, 300);
 chassis.moveToPoint(-36, -33,2100, {.forwards = false, .minSpeed = 30});
fourBar.set_value(false);
scraper.set_value(false);
 pros::delay(1300);
 hoard.set_value(false);
 pros::delay(100);
 arm.move(80);


}










void Low54() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    //to first cluster
   chassis.turnToHeading(19, 100);
   chassis.moveToPoint(7,18, 1000, {.maxSpeed = 70});
   intake.move(127);
   hoard.set_value(true);
   //grab first cluster
   chassis.waitUntil(17);
   scraper.set_value(true);
 
   //to middle
   chassis.turnToHeading(50, 500);
   chassis.moveToPoint(30,39,1000);

   scraper.set_value(false);
    //to long
     chassis.moveToPoint(15,13, 1000, {.forwards = false});
     chassis.turnToHeading(270, 600);
     fourBar.set_value(true);
     moveB(450, false,true, 80, 0, 1500);
     chassis.turnToHeading(180, 500);
     chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 12, 500, {.forwards = false});
     chassis.waitUntil(5);
     hoard.set_value(false);
     arm.move(127);

     pros::delay(300);
     intake.move(-127);
     pros::delay(200);
     arm.move(-127);
     chassis.moveToPoint(chassis.getPose().x - 1, -12, 2000, {.maxSpeed = 60, .minSpeed = 50});
     scraper.set_value(true);
     pros::delay(300);
     arm.move(-10);
     intake.move(127);
     chassis.waitUntilDone();
     left_motors.move(50);
     right_motors.move(50);
     pros::delay(500);
    moveF(460, false, false, 50, 0, 1000);
    scraper.set_value(false);
     chassis.turnToHeading(-44.5, 700);
     chassis.moveToPoint(0, 34, 2500, {.maxSpeed = 90});
     chassis.waitUntilDone();

     intake.move(-127);
     pros::delay(1000);
     chassis.moveToPoint(24.5, 8, 1500, {.forwards = false});
     chassis.turnToHeading(-2, 300);
     wing.set_value(true);
     chassis.moveToPoint(chassis.getPose().x, 40, 1000);
    chassis.turnToHeading(-5, 400);
     //28,8

    
    // //to low
    // chassis.moveToPoint(32, 13, 1000, {.forwards = false});
    // chassis.turnToHeading(-47, 750);
    // chassis.moveToPoint(-8, 46, 2000, {.maxSpeed = 100});
    // chassis.waitUntilDone();
    // intake.move(-127);

    // //to wing
    // pros::delay(500);
    // intake.move(0);
    // chassis.moveToPoint(12, 26, 1500, {.forwards = false, .maxSpeed = 100});
    // chassis.turnToHeading(0, 300);
    // wing.set_value(true);
    // moveB(1000, true, false, 100, 50, 1000);
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
    fourBar.set_value(true);
    moveF(483, true, true, 75, 0, 1000);
    chassis.turnToHeading(270, 600);
    
    intake.move(127);
pros::delay(100);
scraper.set_value(true);
    chassis.moveToPoint(-10, chassis.getPose().y-.5, 1400, {.maxSpeed = 60, .minSpeed = 55});
    chassis.waitUntilDone();
   
left_motors.move(35);
right_motors.move(35);
    chassis.moveToPoint(22,chassis.getPose().y, 1600, {.forwards = false});
    chassis.waitUntil(19);
    hoard.set_value(false);
    
    pros::delay(200);
arm.move(100);

    chassis.waitUntilDone();
    scraper.set_value(false);
    intake.move(-127);
    pros::delay(300);
   

    chassis.moveToPoint(chassis.getPose().x - 7,chassis.getPose().y, 500);
    

    pros::delay(300);
    arm.move(-10);
    chassis.turnToHeading(-40, 400);
    chassis.waitUntilDone();
    chassis.moveToPoint(21, 20, 600, {.forwards = false});
    chassis.turnToHeading(-95, 450);
    chassis.waitUntilDone();
    chassis.moveToPoint(40, 20.7, 1200, {.forwards = false, .maxSpeed = 90});
    wing.set_value(true);
    chassis.waitUntilDone();
    pros::delay(2000);
    chassis.turnToHeading(-80, 700);

}
