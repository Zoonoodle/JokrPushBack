#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/abstract_motor.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

void PIDtune() {
    chassis.turnToHeading(90, 1000);
    chassis.turnToHeading(0, 1000);
}

void elimsMidRush() {
    chassis.setPose(0,-1,0);
    load();
chassis.moveToPoint(-9, 20, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-32, 38, 1300, {.maxSpeed = 100});

chassis.moveToPoint(-4.5, 31, 1000, {.forwards = false} );
chassis.turnToHeading(-136, 600);

extake();
doink.set_value(true);
pros::delay(10);
rest();
chassis.waitUntilDone();
moveB(250, false, true, 100, 650);
// chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});


middleScore();
hoard.set_value(false);
moveB(220, false, true, 75, 500);

pros::delay(600);

chassis.moveToPoint(-29,  3, 900);
middleGetBall();
pros::delay(300);
load();
chassis.turnToHeading(270, 450);
chassis.waitUntilDone();
moveF(495, true, true, 75, 700);
doink.set_value(true);
chassis.turnToHeading(180, 500);
doink.set_value(true);
chassis.moveToPoint(chassis.getPose().x-.2, -12, 1000, { .maxSpeed = 60, .minSpeed = 40,});

load();
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);

pros::delay(200);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(chassis.getPose().x, 21, 1400, {.forwards = false});
chassis.waitUntil(23);






unload();
pros::delay(600);
unload();

pros::delay(600);


doink.set_value(false);
chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 600);
pros::delay(100);
rest();
chassis.turnToHeading(226, 350);
wings.set_value(true);
chassis.moveToPoint(chassis.getPose().x +11, chassis.getPose().y +10, 800, {.forwards = false});
 chassis.turnToHeading(178, 450);
pros::delay(200);
wings.set_value(false);
 chassis.moveToPoint(chassis.getPose().x, 34, 1300, {.forwards = false, .maxSpeed = 70});
chassis.waitUntil(.5);

 chassis.turnToHeading(185, 400, {.minSpeed = 65});
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);


}
void sevenBall() {
    load();
    chassis.moveToPoint(7.5, 21, 800, {.earlyExitRange = 15});
    chassis.swingToHeading(145, DriveSide::RIGHT, 600, {.earlyExitRange = 5});
  

    chassis.moveToPoint(29, 1, 800);
    

    chassis.turnToHeading(89, 600);
    rest();
    chassis.waitUntilDone();
    moveF(495, true, true, 85, 750);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(chassis.getPose().x, -13.5, 1200, {.maxSpeed = 50, .minSpeed = 50});
    doink.set_value(true);
    load();
    chassis.waitUntilDone();
    left_motors.move(30);
    right_motors.move(30);
    pros::delay(400);
    left_motors.move(0);
    right_motors.move(0);
    chassis.moveToPoint(chassis.getPose().x, 20, 1500, {.forwards = false, .maxSpeed = 95});
    chassis.waitUntil(22);


    unload();
    pros::delay(1600);
   
    unload();

   doink.set_value(false);
   chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 700);
   pros::delay(100);
   rest();
   chassis.turnToHeading(-225, 450);
   wings.set_value(true);
   chassis.moveToPoint(chassis.getPose().x -10, chassis.getPose().y +10, 1000, {.forwards = false});
    chassis.turnToHeading(182, 500);
   
    chassis.moveToPoint(chassis.getPose().x +0.25, 29, 1000, {.forwards = false, .maxSpeed = 70});
 chassis.waitUntil(.5);
    wings.set_value(false);
    chassis.turnToHeading(175, 400, {.minSpeed = 65});
 chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
}
void powerBeansAuto() {
    rest();
    hoard.set_value(false);
    chassis.turnToHeading(-26, 500);
    chassis.moveToPoint(11.5,-34, 6000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    intakeTop.move(-50);
    hoard.set_value(true);
    pros::delay(100);
    chassis.moveToPoint(10, -29, 750);
    rest();
    chassis.turnToHeading(270,500);
    chassis.moveToPoint(-18,-25,1000);
    load();
    chassis.turnToHeading(-225,750);
    chassis.moveToPoint(-12,-31.5,1000, {.maxSpeed = 60});
    doink.set_value(true);
    rest();
    chassis.waitUntilDone();
    extake();
    pros::delay(1000);
    rest();
    doink.set_value(false);
    pros::delay(300);
    chassis.turnToHeading(-116,500);
    chassis.moveToPoint(-34,-41,1500, {.earlyExitRange =4});
    load();
    chassis.moveToPoint(-37,-43,1000, {.maxSpeed = 80});
    doink.set_value(true);
    chassis.waitUntilDone();
    chassis.moveToPoint(-20,-37, 1000, {.forwards = false});
    chassis.waitUntil(15);
    rest();
    chassis.turnToHeading(-38,500);
    chassis.moveToPoint(-39,-6,1300);
    chassis.turnToHeading(0,300);
    chassis.moveToPoint(-40.5,11,1000);
    load();
    left_motors.move(60);
    right_motors.move(60);
    pros::delay(750);
    left_motors.move(0);
    right_motors.move(0);
    chassis.moveToPoint(-40, -20, 1000, {.forwards = false});
    chassis.waitUntil(23);
    unload();

}
void SigSawp15Ball() {
    load();
    chassis.moveToPoint(-7.5, 21, 800, {.earlyExitRange = 15});
    chassis.swingToHeading(-145, DriveSide::LEFT, 600, {.earlyExitRange = 5});
  

    chassis.moveToPoint(-29, 1, 800);
    

    chassis.turnToHeading(-89, 600);
    rest();
    chassis.waitUntilDone();
    moveF(495, true, true, 85, 750);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(chassis.getPose().x, -13.5, 1200, {.maxSpeed = 50, .minSpeed = 50});
    doink.set_value(true);
    load();
    chassis.waitUntilDone();
    left_motors.move(30);
    right_motors.move(30);
    pros::delay(400);
    left_motors.move(0);
    right_motors.move(0);
    chassis.moveToPoint(chassis.getPose().x, 20, 1500, {.forwards = false, .maxSpeed = 95});
    chassis.waitUntil(22);


    unload();
    pros::delay(600);
    extake();
    pros::delay(100);
    unload();
    pros::delay(800);
    unload();

   doink.set_value(false);
   doink.set_value(false);
   chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 700);
   pros::delay(100);
   rest();
   chassis.turnToHeading(225, 350);
   wings.set_value(true);
   chassis.moveToPoint(chassis.getPose().x +10, chassis.getPose().y +10, 700, {.forwards = false});
    chassis.turnToHeading(-182, 400);
   pros::delay(200);
    wings.set_value(false);
    chassis.moveToPoint(chassis.getPose().x -0.25, 29, 1000, {.forwards = false, .maxSpeed = 70});

    chassis.turnToHeading(-175, 400, {.minSpeed = 65});
 chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

}
void antiVitalityAuto() {
    load();
    chassis.moveToPoint(-7.5, 21, 800, {.earlyExitRange = 15});
    chassis.swingToHeading(-145, DriveSide::LEFT, 500, {.earlyExitRange = 5});
  

    chassis.moveToPoint(-29, 1, 700);
    

    chassis.turnToHeading(-89, 500);
    rest();
    chassis.waitUntilDone();
    moveF(495, true, true, 85, 750);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(chassis.getPose().x, -13.5, 1200, {.maxSpeed = 50, .minSpeed = 50});
    doink.set_value(true);
    load();
    chassis.waitUntilDone();
    left_motors.move(30);
    right_motors.move(30);
    pros::delay(800);
    left_motors.move(0);
    right_motors.move(0);
    chassis.moveToPoint(chassis.getPose().x, 20, 1500, {.forwards = false, .maxSpeed = 95});
    chassis.waitUntil(22);


    unload();
    
    pros::delay(600);
    extake();
    pros::delay(100);
    unload();
    chassis.waitUntilDone();
    left_motors.move(-100);
    right_motors.move(-100);
    pros::delay(1200);
    unload();
    hoard.set_value(true);

}



void SigSawp() {

chassis.setPose(0,-1,0);
// chassis.moveToPoint(0,30,900);
moveF(500, true, true, 75, 900);
load();
chassis.turnToHeading(90, 550);
doink.set_value(true);


    
chassis.moveToPoint(12,chassis.getPose().y-.1,1000, {.maxSpeed = 65, .minSpeed = 50});
chassis.waitUntilDone();

chassis.moveToPoint(-22,chassis.getPose().y,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(22);
unload();   
doink.set_value(false);
pros::delay(1000);


chassis.moveToPoint(-10, 31,    650, {.earlyExitRange = 5});

chassis.turnToHeading(210, 500);
chassis.moveToPoint(-24.5, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
load();
chassis.moveToPoint(-27, -33, 900, {.earlyExitRange = 6});
chassis.moveToPoint(-27, -44, 400, {.maxSpeed = 80});
// chassis.waitUntil(6);

// doink.set_value(true);
chassis.turnToHeading(137, 500);


chassis.waitUntilDone();
extake();
pros::delay(120);
rest();
moveB(250, false, true, 100, 650);
// chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});


middleScore();
moveB(220, false, true, 75, 500);

pros::delay(600);
left_motors.move(0);
right_motors.move(0);
rest();


chassis.moveToPoint(-5, -70.5, 1250);
pros::delay(100);
extake();   
pros::delay(300);
load();
chassis.turnToHeading(90, 500);
chassis.moveToPoint(12, -70.5, 1200, {.maxSpeed = 60, .minSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(400);
left_motors.move(0);
right_motors.move(0);


chassis.moveToPoint(-21.5, -71, 1250, {.forwards = false});
load();
pros::delay(400);
extake();
pros::delay(100);
rest();
chassis.waitUntil(22);


unload();
chassis.waitUntilDone();


}

 









// --------------------------------------------------------------
