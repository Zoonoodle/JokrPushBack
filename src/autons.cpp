#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

void PIDtune() {
    chassis.turnToHeading(90, 1000);
    chassis.turnToHeading(0, 1000);
}

void elimsMidRush() {
    load();
chassis.moveToPoint(-9, 20, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-32, 39.1, 1300, {.maxSpeed = 100});

chassis.moveToPoint(-4.5, 31, 1000, {.forwards = false} );
chassis.turnToHeading(-135, 500);
extake();
pros::delay(100);
rest();
moveB(170, false, true, 100, 900);
chassis.waitUntil(9);

middleScore();
chassis.waitUntilDone();
pros::delay(950);

load();
chassis.moveToPoint(-33,  3, 1000);
pros::delay(200);
rest();
chassis.turnToHeading(-180, 500);
doink.set_value(true);
chassis.moveToPoint(-34, -12, 1000, {.minSpeed = 30});

load();
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);

pros::delay(250);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-34, 18, 1100, {.forwards = false});
chassis.waitUntil(25);


unload();
pros::delay(1000);
extake();
pros::delay(150);
unload();
pros::delay(900);

chassis.moveToPoint(-34, -12, 1500, {.minSpeed = 30});
load();
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);

pros::delay(400);
left_motors.move(0);
right_motors.move(0);
    
chassis.moveToPoint(-34, 18, 1100, {.forwards = false});
pros::delay(250);
extake();
hoard.set_value(true);
chassis.waitUntil(18);



}


void SigSawp() {

chassis.setPose(0,0,0);
// chassis.moveToPoint(0,30,900);
moveF(405, true, true, 75, 900);
load();
chassis.turnToHeading(90, 450);
doink.set_value(true);


    
chassis.moveToPoint(11,30,1000, {.minSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);



pros::delay(150);
left_motors.move(0);
right_motors.move(0);
chassis.moveToPoint(-22,31,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(24);
unload();   
doink.set_value(false);
pros::delay(1100);


chassis.moveToPoint(-12, 31,    650, {.earlyExitRange = 5});

chassis.turnToHeading(220, 500);
chassis.moveToPoint(-27, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
load();
chassis.moveToPoint(-27, -33, 1000, {.earlyExitRange = 6});
chassis.moveToPoint(-27, -44, 500, {.maxSpeed = 80});
chassis.waitUntil(6);
rest();
doink.set_value(true);
chassis.turnToHeading(136, 450);
chassis.waitUntilDone();
moveB(169, false, true, 100, 900);
// chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});


middleScore();
chassis.waitUntilDone();
pros::delay(1100);

rest();


chassis.moveToPoint(-6, -69, 1250);
pros::delay(100);
extake();
pros::delay(300);
load();
chassis.turnToHeading(90, 500);
chassis.moveToPoint(11, -70, 1000);
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(500);
left_motors.move(0);
right_motors.move(0);


chassis.moveToPoint(-22, -70, 1250, {.forwards = false});
load();
chassis.waitUntil(24);


unload();
chassis.waitUntilDone();


}

void skillsOwen(){

    moveF(405, true, true, 75, 1200);
    load();
    chassis.turnToHeading(90, 500);
    doink.set_value(true);
    
    
        
    chassis.moveToPoint(11,29,1200, {.minSpeed = 40});
    chassis.waitUntilDone();
    left_motors.move(50);
    right_motors.move(50);
    pros::delay(1000);
    left_motors.move(0);
    right_motors.move(0);
    
    chassis.moveToPoint(-22,29.5,1350,{.forwards = false, .minSpeed = 40});
    load();
    chassis.waitUntil(24);
    unload();   
    doink.set_value(false);
    chassis.waitUntilDone();
    
    
 
    pros::delay(1800);
    
    
    chassis.moveToPoint(-12, 31, 650, {.earlyExitRange = 5});
    rest();
    chassis.turnToHeading(205, 500);
    load();
    chassis.moveToPoint(-31, 0, 1500, {.maxSpeed = 70});
    chassis.waitUntil(30);
    doink.set_value(true);
    
    chassis.turnToHeading(234, 400);
    chassis.moveToPoint(-6.7, 27, 1000, {.forwards = false});
    chassis.turnToHeading(93, 450);
    doink.set_value(false);
    chassis.moveToPoint(-22,30,1000,{.forwards = false, .minSpeed = 40});
    chassis.waitUntil(12);
   
    stopUntilScored(2);
  

    chassis.moveToPoint(-12, chassis.getPose().y, 650, {.earlyExitRange = 5});
 
  
chassis.turnToHeading(205, 500);
rest();
chassis.moveToPoint(-27, 4, 600, {.earlyExitRange = 8});

chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});
load();
chassis.moveToPoint(-60, 5.5, 600, {.earlyExitRange = 10});
chassis.moveToPoint(-81.55, 6, 1000, {.maxSpeed = 85});
chassis.waitUntil(12);
doink.set_value(true);
chassis.turnToHeading(180, 400);
chassis.waitUntilDone();
moveF(1010, false, false, 75, 800);
chassis.turnToHeading(320, 550);
rest();

// chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});
extake();
pros::delay(350);
rest();
chassis.waitUntilDone();

rest();
moveB(169, false, true, 90, 2000);
middleScore();
pros::delay(500);
rest();
pros::delay(100);
middleScore();
pros::delay(1800);
}   









// --------------------------------------------------------------
void skills() {
    chassis.turnToHeading(136, 450);
    chassis.waitUntilDone();
    moveB(169, false, true, 100, 900);
    middleScore();
    chassis.waitUntilDone();
    
    pros::delay(1100);
    rest();
    
    chassis.moveToPoint(-6, -69, 1250);
    pros::delay(100);
    extake();
    pros::delay(300);
    load();
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(11, -70, 1000);
    chassis.waitUntilDone();
    
// chassis.moveToPoint(0,30,900);
moveF(405, true, true, 75, 1200);
load();
chassis.turnToHeading(90, 500);
doink.set_value(true);


    
chassis.moveToPoint(11,29,1200, {.minSpeed = 40});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(1500);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-22,29.5,1350,{.forwards = false, .minSpeed = 40});
load();
chassis.waitUntil(24);
unload();   
doink.set_value(false);
chassis.waitUntilDone();


// left_motors.move(-40);
// right_motors.move(-40);
// pros::delay(200);
// left_motors.move(0);
// right_motors.move(0);
pros::delay(900);
rest();
pros::delay(100);
unload();
pros::delay(1600);
hoard.set_value(true);

chassis.moveToPoint(-12, 31, 650, {.earlyExitRange = 5});

chassis.turnToHeading(205, 500);
rest();
chassis.moveToPoint(-27, 4, 800, {.earlyExitRange = 8});

chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});
load();
chassis.moveToPoint(-60, 5.5, 600, {.earlyExitRange = 10});
chassis.moveToPoint(-81.55, 6, 1000, {.maxSpeed = 85});
chassis.waitUntil(12);
doink.set_value(true);
chassis.moveToPoint(-76, 6, 1000, {.forwards = false});
chassis.turnToHeading(320, 550);
rest();

// chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});
extake();
pros::delay(350);
rest();
chassis.waitUntilDone();

rest();
moveB(169, false, true, 90, 2000);
middleScore();
pros::delay(500);
rest();
pros::delay(100);
middleScore();
pros::delay(2300);



chassis.moveToPoint(-100, 29.6, 2000);
rest();
chassis.turnToHeading(269, 500);
chassis.moveToPoint(-115, 30, 1000, {.minSpeed = 30});
load();
chassis.waitUntilDone();

left_motors.move(30);
right_motors.move(30);
pros::delay(1600);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-82, 30.2 , 1200, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(25);
unload();
doink.set_value(false);


pros::delay(2200);
chassis.moveToPoint(chassis.getPose().x - 14                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                , chassis.getPose().y, 800);
chassis.turnToHeading(180, 450);
rest();

chassis.moveToPoint(chassis.getPose().x-.5, chassis.getPose().y-67, 1700, {.earlyExitRange = 15});
chassis.turnToHeading(182, 350);
chassis.waitUntilDone();
moveF(415   , true, true, 75, 1800);
chassis.turnToHeading(272, 600);
doink.set_value(true);
load();
chassis.moveToPoint(-116, -70, 1500, {.minSpeed = 20});
chassis.waitUntilDone();

left_motors.move(30);
right_motors.move(30);
pros::delay(1800);
left_motors.move(0);
right_motors.move(0);

load();

chassis.moveToPoint(-83, -70.5, 1100, {.forwards = false, .minSpeed = 50});
chassis.waitUntil(24);
unload();
pros::delay(2000);
doink.set_value(false);

chassis.moveToPoint(chassis.getPose().x - 15, chassis.getPose().y, 800);
chassis.turnToHeading(40, 450);
load();
chassis.moveToPoint(-75, -47, 1000, {.earlyExitRange = 10});
chassis.swingToHeading(90, DriveSide::RIGHT, 500, {.earlyExitRange = 10});
chassis.moveToPoint(-7, -47.8, 2000, {.maxSpeed = 90});
chassis.waitUntilDone();
chassis.turnToHeading(182, 550);
chassis.waitUntilDone();

// chassis.moveToPoint(chassis.getPose().x , -73.29, 1250);
moveF(385, true, true, 75, 1500);
chassis.turnToHeading(90, 500);
chassis.moveToPoint(-23, chassis.getPose().y, 1250, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(10);
unload();
chassis.waitUntilDone();
left_motors.move(-50);
right_motors.move(-50);
pros::delay(1800);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(9, chassis.getPose().y, 1500, {.minSpeed = 15});
doink.set_value(true);
load();
chassis.waitUntilDone();

left_motors.move(30);
right_motors.move(30);
pros::delay(1800);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-22, -71, 1250, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(24);
unload();
pros::delay(2000);

doink.set_value(false);

chassis.moveToPoint(5.5, -52, 1000);
chassis.waitUntilDone();
chassis.turnToHeading(91, 500);
chassis.waitUntilDone();

moveF(40, true, true, 75, 800);
chassis.turnToHeading(15, 500);
chassis.waitUntilDone();

chassis.moveToPoint(17.5, -13, 3000, {.maxSpeed = 90, .minSpeed = 70, });
extake();
// chassis.moveToPoint(-90, 29, 2000);
// rest();
// chassis.waitUntilDone();
// chassis.turnToHeading(270, 500);
// doink.set_value(true);
// chassis.moveToPoint(-114.7, 29, 1000);
// load();
// loadBallsAuto(6, 1500);

// chassis.moveToPoint(-82.5, 30, 1250, {.forwards = false});
// load();
// chassis.waitUntil(24);
// unload();

// Example usage of moveB function:
// Movement::moveB(300, true, false, 80, 3000);  // Move forward to 300mm (increasing distance)
// Movement::moveB(500, false, true, 100, 5000);  // Move backward to 500mm (decreasing distance)
// Movement::moveB(400, true, false, 90, 4000, true, 45.0);  // With heading hold at 45 degrees

}