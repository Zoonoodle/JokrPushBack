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
    fourBar.set_value(false);
    moveF(490, true, true, 70, 0, 1000);
    chassis.turnToHeading(92, 550);
    
    intake.move(127);
pros::delay(100);
scraper.set_value(true);

    chassis.moveToPoint(10.25, chassis.getPose().y, 1000, {.maxSpeed = 40               , .minSpeed = 40});
    chassis.waitUntilDone();
//    left_motors.move(45);
//    right_motors.move(45);
// pros::delay(1300);
fourBar.set_value(true);
    chassis.moveToPoint(-22,chassis.getPose().y, 1600, {.forwards = false});
    chassis.waitUntil(18);
    hoard.set_value(false);
    
    pros::delay(350);
arm.move(127);

    chassis.waitUntilDone();
    pros::delay(150);
    scraper.set_value(false);
  
    pros::delay(400);
    intake.move(-127);

    chassis.moveToPoint(chassis.getPose().x + 8,chassis.getPose().y, 600);
    

    pros::delay(100);
    arm.move(-127);
    

   chassis.waitUntilDone();
    chassis.turnToHeading(210, 500);
 
    chassis.moveToPoint(-26, 5, 800, {.maxSpeed = 80});
    fourBar.set_value(false);
    intake.move(127);
    arm.move(-10);
    hoard.set_value(true);


   
    chassis.moveToPoint(-29, -34, 800, {.earlyExitRange = 10});
    intake.move(-127);
    
    pros::delay(100);
    intake.move(127);
    chassis.moveToPoint(-29, -40, 800, {.maxSpeed = 80});
    chassis.waitUntil(2);
    scraper.set_value(true);
    

intake.move(127);

chassis.turnToHeading(144,  300);

chassis.moveToPoint(-6, -71, 1000);

intake.move(-127);
pros::delay(150);
intake.move(127);
chassis.turnToHeading(90, 450);
// scraper.set_value(true);
intake.move(127);
pros::delay(200);
fourBar.set_value(true);
chassis.moveToPoint(-23, -71, 1500, {.forwards = false, .maxSpeed = 90, .minSpeed = 50});

chassis.waitUntil(6);
hoard.set_value(false);
intake.move(127);
pros::delay(200);

arm.move(127);


chassis.waitUntilDone();
intake.move(-127);
left_motors.move(0);
right_motors.move(0);
pros::delay(150);
arm.move(-127);

chassis.moveToPoint(0, chassis.getPose().y, 500, {.maxSpeed = 65, .minSpeed = 60, .earlyExitRange = 5});
scraper.set_value(true);
chassis.moveToPoint(12, chassis.getPose().y, 700, {.maxSpeed = 45, .minSpeed = 40});
fourBar.set_value(false);
intake.move(127);
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(300);

intake.move(127);

hoard.set_value(true);



// moveF(535 , false, false, 80, 0, 1000);
chassis.moveToPoint(chassis.getPose().x - 7, chassis.getPose().y, 500, {.forwards = false});

// chassis.turnToHeading(140, 400);
// chassis.waitUntilDone();
// chassis.setPose(0,0,0);
// chassis.moveToPoint(0, -32, 600, {.forwards = false, .earlyExitRange = 5});
fourBar.set_value(false);
scraper.set_value(false);

chassis.moveToPoint(-36.5, -34.25,2000, {.forwards = false, .maxSpeed = 80});
// chassis.moveToPoint(0,-47, 1800, {.forwards = false, .maxSpeed = 70, .minSpeed = 60});

pros::delay(1000);
hoard.set_value(false);
pros::delay(150);
arm.move(80);

chassis.waitUntilDone();
left_motors.move(5);
right_motors.move(5);


//  pros::delay(100);
 




}










void Low54() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    //to first cluster
   chassis.turnToHeading(19, 100);
   chassis.moveToPoint(8,19, 1000, {.maxSpeed = 70});
   intake.move(127);
   hoard.set_value(true);
   //grab first cluster
   chassis.waitUntil(17);
   scraper.set_value(true);
 
   //to middle
   chassis.turnToHeading(50, 500);
   chassis.moveToPoint(30.5,40,1000, {.maxSpeed = 85});

   scraper.set_value(false);
    //to long
     chassis.moveToPoint(15,11, 1200, {.forwards = false});
     chassis.turnToHeading(270, 600);
     fourBar.set_value(true);
     moveB(450, false,true, 80, 0, 1500);
     chassis.turnToHeading(179, 500);
     chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 13, 500, {.forwards = false});
     chassis.waitUntil(5);
     hoard.set_value(false);
     arm.move(127);

     pros::delay(400);
     intake.move(-127);
     pros::delay(400);
     arm.move(-100);
     chassis.moveToPoint(chassis.getPose().x-.5, -12.5, 2000, {.maxSpeed = 55, .minSpeed = 50});
     scraper.set_value(true);
     pros::delay(600);
     arm.move(-10);
     intake.move(127);
     chassis.waitUntilDone();
     hoard.set_value(true);
     left_motors.move(30);
     right_motors.move(30);
     pros::delay(500);
    moveF(460, false, false, 50, 0, 1000);
    scraper.set_value(false);
     chassis.turnToHeading(-45, 700);
     chassis.moveToPoint(-.5, 34, 1650, {.maxSpeed = 65});
pros::delay(1500);

     intake.move(-90);
     chassis.waitUntilDone();
     left_motors.move(-25);
         right_motors.move(-25);
         pros::delay(350);
         left_motors.move(0);
         right_motors.move(0);
         intake.move(-90);
         pros::delay(900);
     chassis.moveToPoint(27, 6, 1500, {.forwards = false});
     chassis.turnToHeading(0, 300);
     wing.set_value(true);
     chassis.moveToPoint(chassis.getPose().x, 38, 1000);
     chassis.waitUntilDone();
    chassis.turnToHeading(-15, 10000);
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
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    //to first cluster

intake.move(127);
chassis.turnToHeading(19, 150);

   chassis.moveToPoint(10,18, 900, {.maxSpeed = 75});

   
   hoard.set_value(true);
   //grab first cluster
   chassis.waitUntil(17);
    scraper.set_value(true);
 
   //to middle
   chassis.turnToHeading(50, 350);
  pros::delay(200);
  scraper.set_value(false);
   chassis.moveToPoint(32,40.5, 1000, {.maxSpeed = 75});
  
    //.back to low
    chassis.moveToPoint(8, 29, 1000, {.forwards = false});
    chassis.turnToHeading(-50, 600);
    // fourBar.set_value(true);
    //go to low
    chassis.moveToPoint(0, 36, 850, {.maxSpeed = 65});
   
    pros::delay(400);
  
         intake.move(-75);
         chassis.waitUntilDone();
         fourBar.set_value(true);
         left_motors.move(-25);
         right_motors.move(-25);
         pros::delay(350);
         left_motors.move(0);
         right_motors.move(0);
         intake.move(-85);
         pros::delay(900);


    //go to matchload
    chassis.moveToPoint(32, 0, 1200, {.forwards = false});
  
    intake.move(127);
    chassis.turnToHeading(269, 500);
    
fourBar.set_value(false);

    chassis.waitUntilDone();
    intake.move(0);
    moveB(420, false, true, 70, 0, 700);

    //turn to match
    chassis.turnToHeading(178, 600);
    scraper.set_value(true);

    chassis.moveToPoint(chassis.getPose().x-.5, -12, 950, {.maxSpeed = 45, .minSpeed = 45});
        intake.move(127);
      
      
        chassis.waitUntilDone();
    left_motors.move(25);
    right_motors.move(25);
    pros::delay(220);


    //move back
    chassis.moveToPoint(chassis.getPose().x, -5, 700, {.forwards = false});
    chassis.turnToHeading(-64, 400);
    scraper.set_value(false);
    
    //go to middle
    chassis.moveToPoint(-37, 26, 2000, {.maxSpeed = 90});
    chassis.turnToHeading(-140, 550);
    chassis.moveToPoint(-26.5, 36.5, 1500, {.forwards = false, .maxSpeed = 55});

    chassis.waitUntil(8);
    hoard.set_value(false);
    pros::delay(150);
    arm.move(115);
    chassis.waitUntilDone();
    left_motors.move(5);
    right_motors.move(5);

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
