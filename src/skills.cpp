#include "autons.h"
#include "fmt/core.h"
#include "lemlib/chassis/chassis.hpp"
#include "movement.h"
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
    // pros::Task unjamTask(intakeUnjamTask);
    fourBar.set_value(false);
    moveF(470, true, true, 65, 0, 1100);
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

    
    wing.set_value(false);
    intake.move(127);
    hoard.set_value(true);
    arm.move(-30);
    chassis.moveToPoint(-9, 25, 600, {.maxSpeed = 70});
  
    scraper.set_value(false);
    chassis.moveToPoint(-10, 26, 700, {.maxSpeed = 65});
   
    fourBar.set_value(true);


    chassis.turnToHeading(-134, 650);
   
    chassis.waitUntilDone();
    pros::delay(100);

    // chassis.moveToPoint(-.5, 32, 1500, {.forwards = false, .maxSpeed = 60});
  
    left_motors.move(-40);
    right_motors.move(-40);
    pros::delay(200);
    scraper.set_value(true);
    pros::delay(350);
    hoard.set_value(false);
    left_motors.move(-25);
    right_motors.move(-25);
    pros::delay(100);
    arm.move(62);
    pros::delay(400);
    arm.move(35);
    intake.move(-127);
    pros::delay(200);
    arm.move(-100);
 
    chassis.moveToPoint(-29, 0, 1400, {.maxSpeed = 85});
    intake.move(127);
    pros::delay(200);
    hoard.set_value(true);
    arm.move(0);
  

   pros::delay(100);
    intake.move(127);
    pros::delay(400);
    
    chassis.turnToHeading(272, 600);
    chassis.waitUntilDone();   
    intake.move(0);
    fourBar.set_value(false);
    moveF(440, true, true, 70, 0, 700);
    chassis.turnToHeading(178, 700);
    scraper.set_value(false);
    hoard.set_value(true);
    intake.move(127);
    

chassis.waitUntilDone();
    left_motors.move(-80);
    right_motors.move(-80);
    pros::delay(600);
    hoard.set_value(false);
    
    arm.move(80);
    pros::delay(250);
    left_motors.move(0);
    intake.move(-127);
    right_motors.move(0);
    pros::delay(600);
    arm.move(-80);
    left_motors.move(59);
    right_motors.move(62);
    scraper.set_value(false);

    pros::delay(600);
   arm.move(-20);
    fourBar.set_value(true);
    hoard.set_value(true);
    intake.move(127);
    left_motors.move(45);
    right_motors.move(45);
    pros::delay(1000);
    left_motors.move(-15);
    right_motors.move(-15);
    pros::delay(300);
    left_motors.move(35);
    right_motors.move(35);
    pros::delay(900);
    moveF(385, false, false, 80, 0, 600);
    // plannedReset(3)
    chassis.waitUntilDone();
    // chassis.setPose(0,0 ,chassis.getPose().theta);
scraper.set_value(true);
    chassis.turnToHeading(150, 450);
    chassis.waitUntilDone();
    left_motors.move(-85);
    right_motors.move(-85);
    pros::delay(300);
    intake.move(0);
    pros::delay(800);

    moveB(660, false, true, 70, 0, 1000);
    chassis.turnToHeading(92, 800);
    chassis.waitUntilDone();
    moveB(450   , true, false, 70, 0, 700);

    chassis.turnToHeading(0, 500);
    fourBar.set_value(false);
    chassis.waitUntilDone();
    chassis.moveToPoint(chassis.getPose().x-1, chassis.getPose().y-16, 1000, {.forwards = false, .maxSpeed = 85, .minSpeed = 50});
    chassis.waitUntil(9);
    hoard.set_value(false);
    intake.move(127);
    chassis.waitUntilDone();
    left_motors.move(-100);
    right_motors.move(-90);
   
    // chassis.waitUntilDone();
    scraper.set_value(false);
    
    pros::delay(500);
    left_motors.move(5);
    right_motors.move(5);
    pros::delay(50);
    arm.move(70);
    left_motors.move(0);
    right_motors.move(0);
    pros::delay(900);
    lemlib::Pose oldPose = chassis.getPose();
    arm.move(-90);
    intake.move(127);
    // moveF(203, true, true, 70, 10, 2500);
    left_motors.move(50);
    right_motors.move(50);
    pros::delay(700);

    fourBar.set_value(true);

    hoard.set_value(true);
    arm.move(-20);
    left_motors.move(45);
    right_motors.move(45);
    pros::delay(1000);
    left_motors.move(-15);
    right_motors.move(-15);
    pros::delay(300);
    left_motors.move(35);
    right_motors.move(35);
    pros::delay(900);
    arm.move(0);
    // chassis.turnToHeading(2, 200);
    chassis.waitUntilDone();
  
    // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 30, 2000, {.forwards = false, .maxSpeed = 85});
    // left_motors.move(-65);
    // right_motors.move(-70);
    // pros::delay(300);
    // fourBar.set_value(false);
    // pros::delay(800);
   
    // hoard.set_value(false);
    // left_motors.move(-120);
    // right_motors.move(-90);
    // pros::delay(600);
        chassis.moveToPoint(oldPose.x, oldPose.y, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 40});
        chassis.waitUntil(5);
        fourBar.set_value(false);
        chassis.waitUntilDone();
        left_motors.move(-70);
        right_motors.move(-60);
        hoard.set_value(false);
        pros::delay(300);
    arm.move(75);
    left_motors.move(0);
    right_motors.move(0);
    pros::delay(500);
    arm.move(-30);
    pros::delay(200);
    arm.move(75);
    intake.move(-127);
    scraper.set_value(true);
    pros::delay(700);
   




    // QUAD 2

   

    pros::delay(100);
    chassis.setPose(0,0, chassis.getPose().theta);
    pros::delay(100);
    scraper.set_value(true);
    arm.move(-70);

        chassis.moveToPose(31,32 , -270, 2400, {.lead = .7, .maxSpeed = 100, .minSpeed = 35, });
    pros::delay(300);
    arm.move(-30);
    // pros::delay(600);
    // scraper.set_value(false);
    // chassis.turnToHeading(80, 300);

    chassis.moveToPoint(105, 33, 4000, {.maxSpeed = 65, .minSpeed = 60});
   
    intake.move(127);
    hoard.set_value(true);
    pros::delay(800);
    scraper.set_value(true);
  
    pros::delay(700);
    // scraper.set_value(false);
    pros::delay(700);
    
    scraper.set_value(true);
    // chassis.moveToPoint(93, 36.5, 1200, {.maxSpeed = 80, .minSpeed = 50});
    chassis.moveToPoint(92, 28, 600, {.forwards = false});
    fourBar.set_value(true);
    chassis.turnToHeading(90, 550);
    chassis.waitUntilDone();
    moveF(1120, false, false, 70, 10, 800);
    chassis.turnToHeading(180, 500);
    chassis.waitUntilDone();
    moveB(180, true, false,50, 0, 500);
    chassis.setPose(0,0,chassis.getPose().theta -180);
    pros::delay(150);
    chassis.moveToPoint(0, 28, 800, {.maxSpeed = 75});
    // chassis.turnToHeading(125, 600);
    fourBar.set_value(true);
    chassis.moveToPoint(1, 39, 700, { .maxSpeed = 70});
    pros::delay(300);
    intake.move(25);
    chassis.waitUntilDone();
    chassis.turnToHeading(-133, 700);
chassis.waitUntilDone();
    
    left_motors.move(-40);
    right_motors.move(-40);
    
    pros::delay(750);
    // chassis.turnToHeading(180, 700);
    // chassis.waitUntilDone();
    // chassis.moveToPose(7.5, 43, -136, 2000, {.forwards = false,.lead = .8, .maxSpeed = 75, .minSpeed = 25});
    

    hoard.set_value(false);
    intake.move(127);
    left_motors.move(-10);
    right_motors.move(-10);
    arm.move(60);
    pros::delay(400);
    arm.move(35);
    pros::delay(600);
    left_motors.move(0);
    right_motors.move(0);
    arm.move(40);
    pros::delay(700);
    chassis.moveToPoint(-18, 13, 1000, {.maxSpeed = 75});
    pros::delay(300);
    intake.move(-127);
    arm.move(-90);

   
  
    
    chassis.turnToHeading(-92, 500);
   arm.move(0);
    chassis.waitUntilDone();

    //3RD QUADRANT

    moveF(460, true, true, 70, 0, 900);
    arm.move(-20);
    scraper.set_value(false);
    chassis.turnToHeading(178, 700);
    
    hoard.set_value(true);
    intake.move(127);
    arm.move(-30);

chassis.waitUntilDone();
    left_motors.move(35);
    right_motors.move(35);
    pros::delay(1300);

    left_motors.move(-15);
    right_motors.move(-15);
    pros::delay(200);
    left_motors.move(45);
    right_motors.move(45);
    pros::delay(900);

    moveF(385, false, false, 80, 0, 600);
    arm.move(0);
    // plannedReset(3)
    chassis.waitUntilDone();
    // chassis.setPose(0,0 ,chassis.getPose().theta);
scraper.set_value(true);
    chassis.turnToHeading(150, 450);
    chassis.waitUntilDone();
    left_motors.move(-85);
    right_motors.move(-85);
    pros::delay(1100);
    intake.move(0);
    moveB(680, false, true, 70, 0, 800);
    chassis.turnToHeading(90, 800);
    chassis.waitUntilDone();
    moveB(440, true, false, 70, 0, 700);

    chassis.turnToHeading(0, 500);
    fourBar.set_value(false);
    chassis.waitUntilDone();
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y-16, 1000, {.forwards = false, .maxSpeed = 85, .minSpeed = 40});
    chassis.waitUntil(8);
    hoard.set_value(false);
    intake.move(127);
    chassis.waitUntilDone();
    left_motors.move(-90);
    right_motors.move(-80);
    pros::delay(400);
    arm.move(70);
    left_motors.move(0);
    right_motors.move(0);
    oldPose = chassis.getPose();
    scraper.set_value(false);
  
    pros::delay(900);
   
    arm.move(-90);
    intake.move(127);
    // moveF(203, true, true, 70, 10, 2500);
    left_motors.move(50);
    right_motors.move(50);
    pros::delay(300);
    fourBar.set_value(true);
    pros::delay(300);
    hoard.set_value(true);
    arm.move(-30);
    left_motors.move(40);
    right_motors.move(40);
    pros::delay(1200);
    left_motors.move(-15);
    right_motors.move(-15);
    pros::delay(300);
    left_motors.move(40);
    right_motors.move(40);
    pros::delay(700);


    chassis.moveToPoint(oldPose.x, oldPose.y, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 40});
    chassis.waitUntil(5);
    fourBar.set_value(false);
    chassis.waitUntilDone();
    left_motors.move(-70);
    right_motors.move(-60);
    hoard.set_value(false);
    // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 30, 2000, {.forwards = false, .maxSpeed = 85});
    // left_motors.move(-65);
    // right_motors.move(-73);
    // pros::delay(1000);
    // left_motors.move(-90);
    // right_motors.move(-90);
    // hoard.set_value(false);
    // pros::delay(200);
   
    arm.move(75);
    left_motors.move(0);
    right_motors.move(0);
    pros::delay(500);
    arm.move(-30);
    pros::delay(100);
    
    intake.move(-127);
    arm.move(75);
    scraper.set_value(true);
    pros::delay(600);


    arm.move(-100);
    arm.move(-127);
    intake.move(-127);
    left_motors.move(-90);
    right_motors.move(-90);

 
    left_motors.move(0);
    right_motors.move(0);
    pros::delay(100);
    arm.move(0);
    chassis.setPose(0,0,0);
    pros::delay(100);
    chassis.moveToPoint(0, 8, 700);
    chassis.turnToHeading(90, 450);
    chassis.waitUntilDone();
    moveB(1650, true, false, 90, 0, 1400);
    chassis.turnToHeading(0, 450);
chassis.waitUntilDone();
intake.move(127);   
left_motors.move(100);
right_motors.move(100);
pros::delay(1000000);



//     chassis.moveToPose(32, 35, 82, 2200, {.lead = .7, .maxSpeed = 100, .minSpeed = 35, });
//     // intake.move(127);
    
//     // arm.move(-120);
//     // pros::delay(350);
//     // arm.move(120);
//     pros::delay(700);
//     arm.move(-40);
//     // fourBar.set_value(true);


    

// chassis.waitUntil(45);
// scraper.set_value(false);

// chassis.moveToPoint(61, 36, 3000, {.maxSpeed = 75, .minSpeed = 55});
 

  
    // intake.move(-127);
    // hoard.set_value(true);


    // pros::delay(2000);
    // left_motors.move(0);
    // right_motors.move(0);
    // QUAD fOUR   WIHT LOW
    // scraper.set_value(true);
    chassis.waitUntilDone();
    scraper.set_value(true);
    pros::delay(100000);
    left_motors.move(0);
    right_motors.move(0);
    chassis.setPose(0,0, 0);
    pros::delay(50);
    chassis.turnToHeading(94, 600);
    chassis.waitUntilDone();
    chassis.moveToPoint(24, -4, 800);
    intake.move(127);
    pros::delay(300);
    // scraper.set_value(false);


    chassis.turnToHeading(224,600);
    fourBar.set_value(true);
    wing.set_value(true);
    chassis.moveToPoint(-5, -31.5, 1000, {.maxSpeed = 70});
    scraper.set_value(true);
    

    chassis.moveToPoint(17, -13, 1200, {.forwards = false, .maxSpeed = 70});
    chassis.turnToHeading(133, 700);
    fourBar.set_value(false);
    chassis.waitUntilDone();
   
// chassis.turnToHeading(130, 500);
chassis.moveToPose(26.5, -20.5, 135,2000, {.maxSpeed = 50, .minSpeed = 30});
intakeLift.set_value(true);

chassis.waitUntilDone();
intake.move(-65);


}
