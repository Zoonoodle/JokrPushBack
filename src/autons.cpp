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
chassis.waitUntilDone();
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

void SigSawp15Ball() {

    load();
chassis.moveToPoint(-9, 20, 600, {.earlyExitRange = 12});
 chassis.moveToPoint(-32, 39.5, 1300, {.maxSpeed = 90, .earlyExitRange = 1});

chassis.moveToPoint(-4.5, 34, 900, {.forwards = false} );
chassis.turnToHeading(-135, 450, {.earlyExitRange = 5});
extake();
pros::delay(100);
rest();
chassis.moveToPoint(1, 38.5, 1300, {.forwards = false, .maxSpeed = 80, .minSpeed = 20} );
chassis.waitUntil(2);

middleScore();
chassis.waitUntilDone();
pros::delay(700);

rest();
chassis.moveToPoint(-35,  3, 1000);
pros::delay(200);

chassis.turnToHeading(-180, 400, {.earlyExitRange = 10});
doink.set_value(true);
chassis.moveToPoint(-35, -12, 1000, {.minSpeed = 30});

load();
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);

pros::delay(175);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-36, 18, 1100, {.forwards = false});
chassis.waitUntil(23);


unload();
pros::delay(1300);
doink.set_value(false);
chassis.moveToPoint(chassis.getPose().x, 8, 600, {.earlyExitRange = 2});
rest();
chassis.turnToHeading(75, 450);
chassis.moveToPoint(38,26, 1100, {.maxSpeed = 110,.earlyExitRange = 10});
chassis.waitUntil(20);
load();
chassis.waitUntilDone();
doink.set_value(true);

chassis.swingToHeading(150, DriveSide::RIGHT, 350, {.earlyExitRange = 5});


chassis.moveToPoint(61, -3, 600);
load();


chassis.turnToHeading(180, 400, {.earlyExitRange = 5});
rest();
doink.set_value(true);

chassis.moveToPoint(61, -13.5, 700, {.minSpeed = 70});
load();
chassis.waitUntilDone();
pros::delay(300);

chassis.moveToPoint(62, 15.5, 1000, {.forwards = false});
chassis.waitUntil(20);
unload();
}

void SigSawp() {

chassis.setPose(0,0,0);
// chassis.moveToPoint(0,30,900);
moveF(505, true, true, 75, 900);
load();
chassis.turnToHeading(90, 450);
doink.set_value(true);


    
chassis.moveToPoint(11,30,1000, {.maxSpeed = 70, .minSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);



pros::delay(100);
left_motors.move(0);
right_motors.move(0);
chassis.moveToPoint(-22,31,1350,{.forwards = false, .maxSpeed = 110});
load();
chassis.waitUntil(22);
unload();   
doink.set_value(false);
pros::delay(1300);


chassis.moveToPoint(-10, 31,    650, {.earlyExitRange = 5});

chassis.turnToHeading(210, 500);
chassis.moveToPoint(-26, 7, 900, {.minSpeed = 50, .earlyExitRange = 10});
load();
chassis.moveToPoint(-27, -33, 1000, {.earlyExitRange = 6});
chassis.moveToPoint(-27, -44, 500, {.maxSpeed = 80});
chassis.waitUntil(6);
rest();
doink.set_value(true);
chassis.turnToHeading(136, 450);
chassis.waitUntilDone();
moveB(220, false, true, 100, 900);
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
chassis.moveToPoint(12, -70, 1000, {.maxSpeed = 75, .minSpeed = 50});
chassis.waitUntilDone();
left_motors.move(30);
right_motors.move(30);
pros::delay(500);
left_motors.move(0);
right_motors.move(0);


chassis.moveToPoint(-22, -70, 1250, {.forwards = false});
load();
chassis.waitUntil(22);


unload();
chassis.waitUntilDone();


}

void skillsOwen(){

    moveF(505, true, true, 75, 1200);
    load();
    chassis.turnToHeading(90, 500);
    doink.set_value(true);
    
    
        
    chassis.moveToPoint(11,29,1500, {.maxSpeed = 60,.minSpeed = 55});
    chassis.waitUntilDone();
    left_motors.move(35);
    right_motors.move(35);
    pros::delay(1000);
    left_motors.move(0);
    right_motors.move(0);
    
    chassis.moveToPoint(-22,29.5,1350,{.forwards = false, .minSpeed = 40});
    load();
    chassis.waitUntil(24);
    unload();   
    doink.set_value(false);
    chassis.waitUntilDone();
    
    
 
    pros::delay(1500);
    
    
    chassis.moveToPoint(-12, 31, 650, {.earlyExitRange = 5});
    rest();
    chassis.turnToHeading(190, 500);
    load();
    chassis.moveToPoint(-31, 0, 1500, {.maxSpeed = 60});
    chassis.waitUntil(27);
    doink.set_value(true);
    
    chassis.turnToHeading(234, 400);
    chassis.moveToPoint(-6.7, 29, 1000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    doink.set_value(false);
    chassis.moveToPoint(-22,chassis.getPose().y,1000,{.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
   
    unload();
    pros::delay(450);
    rest();
    hoard.set_value(true);

  

    chassis.moveToPoint(-12, chassis.getPose().y, 650, {.earlyExitRange = 5});
 extake();
 pros::delay(120);
 rest();
chassis.turnToHeading(205, 500);
rest();
chassis.moveToPoint(-27, 4, 600, {.earlyExitRange = 8});

chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});
load();
chassis.moveToPoint(-60, 5.5, 600, {.earlyExitRange = 10});
chassis.moveToPoint(-82, 6, 1000, {.maxSpeed = 85});
chassis.waitUntil(12);
doink.set_value(true);
chassis.turnToHeading(270, 400);
chassis.waitUntilDone();
moveF(1140, false, false, 110, 700);
chassis.turnToHeading(320, 550);
rest();

// chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});

chassis.waitUntilDone();
extake();
pros::delay(125);
rest();


rest();

//MIDDLE SCORE
moveB(255, false, true, 80, 900);
middleScore();
left_motors.move(-12);
right_motors.move(-12);
pros::delay(1000);
left_motors.move(0);
right_motors.move(0);
rest();
pros::delay(50);
middleScore();
pros::delay(1250);



doink.set_value(false);
chassis.moveToPoint(-100, 22, 1000);
rest();
chassis.turnToHeading(0, 500);
moveF(495, true, true, 85, 1200);

chassis.turnToHeading(270, 500);
doink.set_value(true);
chassis.moveToPoint(-117, chassis.getPose().y, 1000, {.maxSpeed = 60,.minSpeed = 60});
load();
chassis.waitUntilDone();

left_motors.move(35);
right_motors.move(35);
pros::delay(1200);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-82, 30.2 , 1200, {.forwards = false,  .maxSpeed = 80, .minSpeed = 40});
chassis.waitUntil(25);
unload();
doink.set_value(false);

chassis.waitUntilDone();
pros::delay(800);
slowUnload();

chassis.moveToPoint(chassis.getPose().x - 12                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                , chassis.getPose().y, 800);
chassis.turnToHeading(180, 450);
rest();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

chassis.moveToPoint(chassis.getPose().x-.5, chassis.getPose().y-69, 1700);
chassis.waitUntilDone();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);


chassis.turnToHeading(183, 350);
chassis.waitUntilDone();
moveF(510   , true, true, 75, 1400);
chassis.turnToHeading(272, 600);
doink.set_value(true);
load();
chassis.moveToPoint(-116.5, chassis.getPose().y+.5, 1200, {.maxSpeed = 60,.minSpeed = 50});
chassis.waitUntilDone();

left_motors.move(30);
right_motors.move(30);
pros::delay(1400);
left_motors.move(0);
right_motors.move(0);

load();

chassis.moveToPoint(-83, chassis.getPose().y-1.5, 1100, {.forwards = false,  .maxSpeed = 80, .minSpeed = 50});
chassis.waitUntil(24);
unload();
chassis.waitUntilDone();
pros::delay(1200);
doink.set_value(false);

chassis.moveToPoint(chassis.getPose().x - 15, chassis.getPose().y, 800);
chassis.turnToHeading(40, 450);
load();
chassis.moveToPoint(-77, -43, 1200, {.maxSpeed = 60});
chassis.waitUntil(18);
doink.set_value(true);
chassis.waitUntilDone();


chassis.moveToPoint(-100, -69, 1200, {.forwards = false});
chassis.waitUntilDone();

chassis.turnToHeading(270, 800);
chassis.waitUntilDone();

chassis.moveToPoint(-83, -69, 1000, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(15);
unload();
doink.set_value(false);
pros::delay(900);

chassis.moveToPoint(chassis.getPose().x - 15, chassis.getPose().y, 800);

chassis.turnToHeading(40, 450);
chassis.moveToPoint(-68, -43, 600, {.earlyExitRange = 10});
chassis.turnToHeading(100, 400);
chassis.moveToPoint(-44, -56, 600, {.earlyExitRange = 10});
chassis.moveToPoint(-5, -56, 800);
chassis.turnToHeading(180, 500);
chassis.waitUntilDone();
moveF(500, true, true, 75, 1300);
chassis.turnToHeading(90, 500);
doink.set_value(true);
load();

    
chassis.moveToPoint(11,chassis.getPose().y ,1300, {.maxSpeed = 60,.minSpeed = 60});
chassis.waitUntilDone();
left_motors.move(25);
right_motors.move(25);
pros::delay(1000);
left_motors.move(0);
right_motors.move(0);
chassis.moveToPoint(-22, chassis.getPose().y, 1250, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(23);
unload();

chassis.waitUntilDone();
pros::delay(1400);
doink.set_value(false);


chassis.moveToPoint(13, -56.5, 600);
chassis.turnToHeading(9, 300);
extake();
chassis.moveToPoint(17, -23, 3000, {.maxSpeed = 85, .minSpeed = 75});
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
moveF(505, true, true, 75, 1200);
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
moveF(515   , true, true, 75, 1800);
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
moveF(485, true, true, 75, 1500);
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

moveF(50, true, true, 75, 800);
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