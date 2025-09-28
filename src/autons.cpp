#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"

void PIDtune() {
    chassis.turnToHeading(90, 500);
    chassis.turnToHeading(0, 500);
}

void elimsMidRush() {
    load();
chassis.moveToPoint(-9, 20, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-30.5, 40.5, 1300, {.maxSpeed = 100});

chassis.moveToPoint(-4.5, 30.5, 1000, {.forwards = false} );
chassis.turnToHeading(-131, 500);
extake();
pros::delay(100);
rest();
chassis.moveToPoint(2.85, 36.051, 1500, {.forwards = false, .maxSpeed = 110});
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
chassis.moveToPoint(-34, -12, 1000);

load();
loadBallsAuto(7, 1500);
chassis.moveToPoint(-34, 18, 1100, {.forwards = false});
chassis.waitUntil(25);


unload();
    
}


void SigSawp() {

chassis.setPose(0,0,0);
chassis.moveToPoint(0,30,900);
load();
chassis.turnToHeading(90, 500);
doink.set_value(true);


    
chassis.moveToPoint(11,30,1000, {.minSpeed = 50});
chassis.waitUntilDone();
loadBallsAuto(2, 400);

chassis.moveToPoint(-22,31,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(24);
unload();   
doink.set_value(false);
scoreBallsAuto(4, 1100);


chassis.moveToPoint(-12, 31,    650, {.earlyExitRange = 5});

chassis.turnToHeading(220, 500);
chassis.moveToPoint(-27, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
load();
chassis.moveToPoint(-27, -33, 1000, {.earlyExitRange = 6});
chassis.moveToPoint(-28, -44, 500, {.maxSpeed = 80});
chassis.waitUntil(6);
rest();
doink.set_value(true);
chassis.turnToHeading(135, 450);

chassis.moveToPoint(-39.8, -32.1, 1500, {.forwards = false});

chassis.waitUntil(10);

middleScore();
chassis.waitUntilDone();
pros::delay(900);

rest();


chassis.moveToPoint(-6, -69, 1250);
pros::delay(100);
extake();
pros::delay(300);
load();
chassis.turnToHeading(90, 500);
chassis.moveToPoint(11, -70, 1000);
chassis.waitUntilDone();
loadBallsAuto(2, 550);

chassis.moveToPoint(-22, -70, 1250, {.forwards = false});
load();
chassis.waitUntil(24);


unload();
chassis.waitUntilDone();


}

void skills() {
    chassis.moveToPoint(0,30,900);
load();
chassis.turnToHeading(90, 500);
doink.set_value(true);


    
chassis.moveToPoint(11,29,1000);
chassis.waitUntilDone();
loadBallsAuto(6, 1700);

chassis.moveToPoint(-22,30,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(24);
unload();   
doink.set_value(false);
pros::delay(2000);
hoard.set_value(true);
left_motors.move(-40);
right_motors.move(-40);
pros::delay(200);
left_motors.move(0);
right_motors.move(0);
chassis.moveToPoint(-12, 31, 650, {.earlyExitRange = 5});

chassis.turnToHeading(205, 500);
rest();
chassis.moveToPoint(-27, 4, 1200, {.maxSpeed = 100});
load();
chassis.turnToHeading(270, 500);
chassis.moveToPoint(-60, 5.5, 900, {.earlyExitRange = 10});
chassis.moveToPoint(-81.55, 6, 1000, {.maxSpeed = 85});
chassis.waitUntil(12);
doink.set_value(true);
chassis.moveToPoint(-77, 6, 800, {.forwards = false});
chassis.turnToHeading(315, 500);
rest();
chassis.moveToPoint(-63.5, -7.2, 1800, {.forwards = false, .maxSpeed = 65});
chassis.waitUntil(10);
middleScore();
chassis.waitUntilDone();
left_motors.move(12);
right_motors.move(12);
pros::delay(200);
left_motors.move(0);
right_motors.move(0);
extake();
pros::delay(200);
middleScore();
pros::delay(1550);
slowMiddleScore();
pros::delay(500);

chassis.moveToPoint(-102, 30, 1500);
chassis.turnToHeading(270, 700);
chassis.moveToPoint(-115, 31, 1000, {.minSpeed = 30});
load();
chassis.waitUntilDone();
loadBallsAuto(6, 1500);
chassis.moveToPoint(-82, 31, 1000, {.forwards = false});
chassis.waitUntil(28);
slowUnload();
doink.set_value(false);
pros::delay(2500);
chassis.moveToPoint(chassis.getPose().x - 5, chassis.getPose().y, 700);
chassis.turnToHeading(160, 500);
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
// pros::delay(600);
// slowUnload();
// doink.set_value(false);
// pros::delay(2750);

// Example usage of moveB function:
// Movement::moveB(300, true, false, 80, 3000);  // Move forward to 300mm (increasing distance)
// Movement::moveB(500, false, true, 100, 5000);  // Move backward to 500mm (decreasing distance)
// Movement::moveB(400, true, false, 90, 4000, true, 45.0);  // With heading hold at 45 degrees

}