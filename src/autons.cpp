#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "movement.h"
#include "pros/abstract_motor.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

void PIDtune() {
    chassis.turnToHeading(90, 1000);
    chassis.turnToHeading(0, 1000);
}

void elimsMidRush() {
    chassis.setPose(0,-1,0);
    load();
chassis.moveToPoint(-9, 21, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-32.25, 39, 1200, {.maxSpeed = 80});
 

chassis.moveToPoint(-4.5, 31, 1000, {.forwards = false} );
rest();
pros::delay(100);
load();
chassis.turnToHeading(-136, 600);
doink.set_value(true);


// pros::delay(250);
// extake();
// pros::delay(205);

chassis.waitUntilDone();
left_motors.move(-60);
right_motors.move(-60);
intakeTop.move(-127);
pros::delay(200);

left_motors.move(0);
right_motors.move(0);

// chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});

middleScore();
hoard.set_value(false);
moveB(220, false, true, 50, 0, 600);
pros::delay(1100);
middleGetBall();

chassis.moveToPoint(-29,  3, 900);
pros::delay(300);
rest();
chassis.turnToHeading(270, 450);
chassis.waitUntilDone();
moveF(520, true, true, 75, 0, 700);
doink.set_value(true);
chassis.turnToHeading(180, 500);
doink.set_value(true);
chassis.moveToPoint(chassis.getPose().x-.2, -10, 400);
load();
chassis.waitUntilDone();
left_motors.move(40);
right_motors.move(40);
pros::delay(510);
load();
chassis.waitUntilDone();


chassis.moveToPoint(chassis.getPose().x, 21, 1400, {.forwards = false, .maxSpeed = 90});
chassis.waitUntil(22);






unload();
pros::delay(1200);



doink.set_value(false);
chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 500);
pros::delay(100);
rest();
chassis.turnToHeading(226, 350);
wings.set_value(true);
chassis.moveToPoint(chassis.getPose().x +10, chassis.getPose().y +10, 600, {.forwards = false});
 chassis.turnToHeading(173, 350);
pros::delay(200);
wings.set_value(false);
 chassis.moveToPoint(chassis.getPose().x, 34, 1300, {.forwards = false, .maxSpeed = 70});
chassis.waitUntil(.5);

//  chassis.turnToHeading(185, 400, {.minSpeed = 65});
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
    moveF(495, true, true, 85, 0, 750);
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
    wings.set_value(true);
load();

chassis.moveToPoint(0, 6, 300, {.minSpeed = 30});

// chassis.moveToPoint(0,30,900);
left_motors.move(-80);
right_motors.move(-80);
pros::delay(200);
rest();
pros::delay(500);
left_motors.move(0);
right_motors.move(0);

moveB(395, false, true, 70, 0, 1500);
chassis.turnToHeading(270, 550);
load();
pros::delay(250);
doink.set_value(true);
chassis.waitUntilDone();

chassis.setPose(0,0,0);
chassis.moveToPoint(0, 11.25, 1200, {.maxSpeed = 65, .minSpeed = 50});
chassis.waitUntilDone();
pros::delay(500);
load();


chassis.moveToPoint(chassis.getPose().x-.5,-19,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(20);
unload();   
doink.set_value(false);

pros::delay(1200);
chassis.moveToPoint(0, chassis.getPose().y +8, 450);
load();
chassis.turnToHeading(115, 450);
chassis.moveToPoint(28, -25.5, 900, {.minSpeed = 40, .earlyExitRange = 10});

// chassis.moveToPoint(55, -26, 600, {.earlyExitRange = 10});
chassis.moveToPoint(74, -26, 1400);
chassis.waitUntil(40);

chassis.turnToHeading(50, 450);
pros::delay(150);
extake();
pros::delay(100);
rest();
doink.set_value(false);
chassis.moveToPoint(63, -35, 1300, {.forwards = false , .maxSpeed = 70, .minSpeed = 40});
pros::delay(200);

middleScore();
chassis.waitUntilDone();
pros::delay(600);


middleGetBall();
chassis.moveToPoint(101, -4, 1200);
pros::delay(150);
load();
chassis.turnToHeading(0, 500);
pros::delay(100);
doink.set_value(true);
chassis.moveToPoint(chassis.getPose().x+.5, 13, 1200, {.maxSpeed = 65, .minSpeed = 50});
chassis.waitUntilDone();
pros::delay(400);
chassis.moveToPoint(chassis.getPose().x-.5, -17, 1250, {.forwards = false});
chassis.waitUntil(20);
unload();
// load();
// chassis.turnToHeading(90, 550);
// doink.set_value(true);


    
// chassis.moveToPoint(12,chassis.getPose().y-.1,1000, {.maxSpeed = 65, .minSpeed = 50});
// chassis.waitUntilDone();

// chassis.moveToPoint(-22,chassis.getPose().y,1350,{.forwards = false, .maxSpeed = 110});
// load();
// chassis.waitUntil(22);
// unload();   
// doink.set_value(false);
// pros::delay(1000);


// chassis.moveToPoint(-10, 31,    650, {.earlyExitRange = 5});

// chassis.turnToHeading(210, 500);
// chassis.moveToPoint(-24.5, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
// load();
// chassis.moveToPoint(-27, -33, 900, {.earlyExitRange = 6});
// chassis.moveToPoint(-27, -44, 400, {.maxSpeed = 80});
// // chassis.waitUntil(6);

// // doink.set_value(true);
// chassis.turnToHeading(137, 500);


// chassis.waitUntilDone();
// doink.set_value(true);
// pros::delay(20);
// extake();
// pros::delay(50);
// rest();
// moveB(250, false, true, 100, 0, 650);
// // chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});


// middleScore();
// moveB(220, false, true, 75, 0, 500);

// pros::delay(600);
// left_motors.move(0);
// right_motors.move(0);
// rest();


// chassis.moveToPoint(-5, -71, 1250);
// pros::delay(100);
// extake();   
// pros::delay(300);
// load();
// chassis.turnToHeading(90, 500);
// doink.set_value(true);
// chassis.moveToPoint(12, -71, 1200, {.maxSpeed = 50, .minSpeed = 50});
// chassis.waitUntilDone();
// left_motors.move(30);
// right_motors.move(30);
// pros::delay(400);
// left_motors.move(0);
// right_motors.move(0);


// chassis.moveToPoint(-21.5, -71, 1250, {.forwards = false, .maxSpeed = 90, .minSpeed = 30});
// load();
// pros::delay(400);
// extake();
// doink.set_value(false);
// pros::delay(100);
// rest();
// chassis.waitUntil(22);


// unload();
// chassis.waitUntilDone();

}
void lateMidSawp() {

}
void antiVitalityAuto() {
    wings.set_value(false);
    chassis.setPose(0,-1,0);
    load();
chassis.moveToPoint(9, 21, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(32.5, 39, 1300, {.maxSpeed = 90});
// chassis.waitUntil(22);
// doink.set_value(true);
// pros::delay(200);
// doink.set_value(false);
chassis.moveToPoint(16, 10.5,  1600, {.forwards = false} );
doink.set_value(false);
chassis.turnToHeading(270, 500);
chassis.waitUntilDone();
moveB(465, false, true, 80, 0, 1200);
// chassis.moveToPoint(40,  6, 1300, {.forwards = false});
chassis.waitUntilDone();

chassis.turnToHeading(180, 550);
extake();
pros::delay(100);
rest();
chassis.waitUntilDone();

chassis.moveToPoint(40, 17, 1000, {.forwards = false});
chassis.waitUntil(3);
unload();
pros::delay(1500);

// chassis.turnToHeading(-270, 450);
// chassis.waitUntilDone();
// moveF(510, true, true, 75, 0, 700);
doink.set_value(true);
// chassis.turnToHeading(180, 500);
// doink.set_value(true);
chassis.moveToPoint(chassis.getPose().x, -6, 600, {.earlyExitRange = 2});
rest();
chassis.moveToPoint(chassis.getPose().x, -14, 1500, { .maxSpeed = 55, .minSpeed = 55,});

load();
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(600);

chassis.moveToPoint(chassis.getPose().x, 20.5, 1400, {.forwards = false, .maxSpeed = 90});
chassis.waitUntil(22);






unload();
pros::delay(1500);
hoard.set_value(true);
pros::delay(150);


doink.set_value(false);
chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 600);
pros::delay(100);
rest();
chassis.turnToHeading(-226, 350);
wings.set_value(true);
chassis.moveToPoint(chassis.getPose().x -17, chassis.getPose().y +28, 1250, {.forwards = false});
 chassis.turnToHeading(90, 450);
pros::delay(200);
wings.set_value(false);
 chassis.moveToPoint(chassis.getPose().x+15, chassis.getPose().y, 1300, {.maxSpeed = 70});


}



void SigSawp() {
wings.set_value(true);
chassis.setPose(0,-1,0);
// chassis.moveToPoint(0,30,900);
moveF(510, true, true, 75, 0, 900);
load();
chassis.turnToHeading(90, 550);
doink.set_value(true);


    
chassis.moveToPoint(12,chassis.getPose().y-.1,1000, {.maxSpeed = 65, .minSpeed = 50});
chassis.waitUntilDone();

chassis.moveToPoint(-22,chassis.getPose().y,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(20);
unload();   
doink.set_value(false);
pros::delay(1200);


chassis.moveToPoint(-10, 31,    650, {.earlyExitRange = 5});

chassis.turnToHeading(210, 500);
chassis.moveToPoint(-25.5, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
load();
chassis.moveToPoint(-27, -33, 900, {.earlyExitRange = 6});
chassis.moveToPoint(-27, -44, 400, {.maxSpeed = 80});
// chassis.waitUntil(6);

// doink.set_value(true);
chassis.turnToHeading(130, 500);


chassis.waitUntilDone();
doink.set_value(true);
pros::delay(20);
extake();
pros::delay(70);
rest();
chassis.moveToPoint(-37.5, -32, 1100, {.forwards = false, .maxSpeed = 70});
extake();
pros::delay(140);
rest();
chassis.waitUntil(6);
middleScore();
chassis.waitUntilDone();
pros::delay(650);




chassis.moveToPoint(-5, -71, 1250);
middleGetBall();
pros::delay(200);

load();
chassis.turnToHeading(90, 500);
doink.set_value(true);
chassis.moveToPoint(12.15, -71, 1200, {.maxSpeed = 60, .minSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(400);
left_motors.move(0);
right_motors.move(0);


chassis.moveToPoint(-21.5, -71, 1250, {.forwards = false, .maxSpeed = 90, .minSpeed = 30});
load();
pros::delay(400);
extake();
doink.set_value(false);
pros::delay(100);
rest();
chassis.waitUntil(22);


unload();
chassis.waitUntilDone();


}

 

void leftSideNineBall() {
// 
}


void leftSide4ball() {
    chassis.setPose(0,-1,0);
    load();
chassis.moveToPoint(-9, 21, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-32.25, 39, 1200, {.maxSpeed = 80});
 

chassis.moveToPoint(-25, 12, 800, {.forwards = false} );
rest();
pros::delay(100);
load();
    load();

chassis.waitUntilDone();

chassis.moveToPoint(-42, 6.5, 1200, {.forwards = false});
chassis.turnToHeading(175, 500);
chassis.moveToPoint(-42, 17.5, 1500, {.forwards = false, .minSpeed = 20});
pros::delay(400);
unload();
pros::delay(1800);



chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 11, 600);
pros::delay(100);
rest();
chassis.turnToHeading(226, 300);
wings.set_value(true);
chassis.moveToPoint(chassis.getPose().x +10, chassis.getPose().y +10, 650, {.forwards = false});
 chassis.turnToHeading(173, 300);
pros::delay(100);
wings.set_value(false);
 chassis.moveToPoint(chassis.getPose().x, 34, 1300, {.forwards = false, .maxSpeed = 70});
chassis.waitUntil(.5);
}







// // --------------------------------------------------------------
