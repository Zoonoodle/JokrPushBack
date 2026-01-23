#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"
#include <ios>


void skillsOwen(){
chassis.setPose(0,-1,0);
    moveF(505, true, true, 75, 0, 1200);
    load();
    chassis.turnToHeading(90, 500);
    doink.set_value(true);
    
    
        
    chassis.moveToPoint(9,chassis.getPose().y,500);
chassis.waitUntilDone();
    // left_motors.move(30);
    left_motors.move(40);
    right_motors.move(40);
pros::delay(1500);
    chassis.moveToPoint(-22,chassis.getPose().y+1.25,1350,{.forwards = false, .maxSpeed = 90, .minSpeed = 40});
    extake();
    pros::delay(200);
  load();
  chassis.waitUntil(20);
    unload();   
    doink.set_value(false);
    chassis.waitUntilDone();
    
    
 
    pros::delay(1650);
    
    
    chassis.moveToPoint(-12, 31, 650, {.earlyExitRange = 5});
    rest();
    chassis.turnToHeading(190, 500);
    load();
    chassis.moveToPoint(-29.5, 0, 1500, {.maxSpeed = 60});
    chassis.waitUntil(20);
    doink.set_value(true);
    
    chassis.turnToHeading(234, 400);
    chassis.moveToPoint(-6.7, 30.5, 1200, {.forwards = false});
    chassis.turnToHeading(90, 750);
    doink.set_value(false);
    chassis.moveToPoint(-22,30,1000,{.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
   
    unload();
    pros::delay(500);
    rest();
    hoard.set_value(true);

  

    chassis.moveToPoint(-12, chassis.getPose().y, 650, {.earlyExitRange = 5});
 extake();
 pros::delay(120);
 rest();
chassis.turnToHeading(205, 500);
rest();
chassis.moveToPoint(-27, 7, 600, {.earlyExitRange = 8});

chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});
extake();
pros::delay(80);
rest();
chassis.moveToPoint(-60, 7.5, 600, {.earlyExitRange = 10});
rest();
chassis.moveToPoint(-82, 8, 600, {.maxSpeed = 85});
load();
chassis.waitUntil(12);
doink.set_value(true);
chassis.turnToHeading(270, 400);
chassis.waitUntilDone();
moveF(1130, false, false, 110, 0, 650);
chassis.turnToHeading(322, 550);
rest();

// chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});

chassis.waitUntilDone();
extake();
pros::delay(150);
rest();


rest();

//MIDDLE SCORE make htis odom
// moveB(250, false, true, 100, 0, 750);

// middleScore();
// moveB(220, false, true, 75, 0, 600);
chassis.moveToPoint(-64.5, -5.3, 1000, {.forwards = false, .maxSpeed = 70});

chassis.waitUntil(7);
middleScore();
pros::delay(800);
extake();
pros::delay(100);
rest();
slowMiddleScore();


pros::delay(800);


middleScore();
doink.set_value(false);
chassis.moveToPoint(-98, 22, 1200, {.maxSpeed = 85});

chassis.turnToHeading(0, 500);
rest();
chassis.waitUntilDone();

moveF(510, true, true, 85, 0, 1200);

chassis.turnToHeading(270, 500);
doink.set_value(true);
chassis.moveToPoint(-114, chassis.getPose().y, 500);
load();
chassis.waitUntilDone();
left_motors.move(35);
right_motors.move(35);
pros::delay(1500);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-82, chassis.getPose().y+1, 1200, {.forwards = false,  .maxSpeed = 80, .minSpeed = 40});
chassis.waitUntil(23.5);
unload();
doink.set_value(false);

chassis.waitUntilDone();
pros::delay(700);

pros::delay(1000);


chassis.moveToPoint(chassis.getPose().x - 13, chassis.getPose().y, 800);
chassis.turnToHeading(180, 450);
rest();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

chassis.moveToPoint(chassis.getPose().x-.5, chassis.getPose().y-83, 2000, {.maxSpeed = 95});
chassis.waitUntilDone();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);


chassis.turnToHeading(183, 350);
chassis.waitUntilDone();
moveF(508, true, true, 75, 0, 1000);
chassis.turnToHeading(273.5, 600);
doink.set_value(true);
load();
chassis.moveToPoint(-114, chassis.getPose().y+.5, 600);
chassis.waitUntilDone();
left_motors.move(40);
right_motors.move(40);
pros::delay(1500);
left_motors.move(0);
right_motors.move(0);

load();

chassis.moveToPoint(-83, chassis.getPose().y-1.5, 1100, {.forwards = false,  .maxSpeed = 80, .minSpeed = 50});
chassis.waitUntil(22);
unload();
chassis.waitUntilDone();
pros::delay(1200);
doink.set_value(false);

chassis.moveToPoint(chassis.getPose().x - 15, chassis.getPose().y, 800);
chassis.turnToHeading(40, 450);
load();
chassis.moveToPoint(-79, chassis.getPose().y + 26, 1200, {.maxSpeed = 60});
chassis.waitUntil(18);
doink.set_value(true);
chassis.waitUntilDone();


chassis.moveToPoint(-100.5, chassis.getPose().y - 25.5, 1200, {.forwards = false});
chassis.waitUntilDone();

chassis.turnToHeading(270, 800);
chassis.waitUntilDone();

chassis.moveToPoint(-83, chassis.getPose().y-.1, 1000, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(15);
unload();
doink.set_value(false);
pros::delay(1100);

chassis.moveToPoint(chassis.getPose().x - 11, chassis.getPose().y, 700);

chassis.turnToHeading(0, 450);
chassis.waitUntilDone();
// chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y +27, 900);
moveB(985, true, false, 80, 0, 850);
chassis.turnToHeading(90, 450);

// chassis.moveToPoint(-44, -56, 800, {.earlyExitRange = 10});
chassis.moveToPoint(-12, chassis.getPose().y, 2000, {.maxSpeed = 95});
chassis.turnToHeading(180, 500);
chassis.waitUntilDone();
moveF(510, true, true, 75, 0, 1200);
chassis.turnToHeading(90, 500);
doink.set_value(true);
load();

chassis.moveToPoint(7, chassis.getPose().y, 600);
chassis.waitUntilDone();
left_motors.move(35);
right_motors.move(35);

pros::delay(1300);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-25.5, chassis.getPose().y-.75, 1250, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(23);
unload();

chassis.waitUntilDone();
left_motors.move(-95);
right_motors.move(-95);
pros::delay(1400);
left_motors.move(0);
right_motors.move(0);

doink.set_value(false);
chassis.moveToPoint(chassis.getPose().x+14, chassis.getPose().y , 600);
rest();
chassis.turnToHeading(1.5, 500);
chassis.waitUntilDone();
moveB(1670, true, false, 100,0, 1600);
// chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y +48, 1450);
chassis.turnToHeading(90, 450);
wings.set_value(true);
chassis.waitUntilDone();
left_motors.move(75);
right_motors.move(75);
unload();



}




///END

// void riskySkills(){
//     enableUnjam();
//     moveF(500, true, true, 75, 1200);
//     load();
//     chassis.turnToHeading(90, 500);
//     doink.set_value(true);
    
    
        
//     chassis.moveToPoint(11,chassis.getPose().y,1000, {.maxSpeed = 60,.minSpeed = 55});
//     chassis.waitUntilDone();
//     pros::delay(1200);
//     chassis.moveToPoint(-22,29.5,1350,{.forwards = false, .minSpeed = 40});
//     load();
//     chassis.waitUntil(24);
//     unload();   
//     doink.set_value(false);
//     chassis.waitUntilDone();
    
    
 
//     // pros::delay(300);
//     // extake();
//     // pros::delay(150);
//     // unload();
//     //pros::delay(1750);
//     pros::delay(2000);
//     chassis.moveToPoint(-10, 31, 650, {.earlyExitRange = 5});
    
//     chassis.turnToHeading(210, 500);
//     rest();
//     load();
//     chassis.moveToPoint(-31, 0, 1000, {.maxSpeed = 100});
//     chassis.waitUntil(27);
//     doink.set_value(true);
    
//     chassis.turnToHeading(234, 400);
//     chassis.moveToPoint(-6.7, 31, 1200, {.forwards = false});
//     chassis.turnToHeading(90, 750);
//     doink.set_value(false);
//     chassis.moveToPoint(-22,chassis.getPose().y,1000,{.forwards = false, .minSpeed = 40});
//     chassis.waitUntilDone();
   
//     unload();
//     pros::delay(400);
//     rest();
//     hoard.set_value(true);

  

//     chassis.moveToPoint(-12, chassis.getPose().y, 650, {.earlyExitRange = 5});
//  extake();
//  pros::delay(120);
//  rest();
// chassis.turnToHeading(205, 500);
// slowExtake();
// chassis.moveToPoint(-27, 7, 600, {.earlyExitRange = 8});
// slowExtake();
// chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});

// chassis.moveToPoint(-70, 9, 600, {.earlyExitRange = 10});
// chassis.moveToPoint(-87, 10, 1000, {.maxSpeed = 85});
// load();
// chassis.waitUntil(4);
// doink.set_value(true);
// chassis.turnToHeading(270, 450);
// chassis.waitUntilDone();
// moveF(1090, false, false, 110, 1000);
// chassis.turnToHeading(318, 550);
// rest();

// // chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});

// chassis.waitUntilDone();
// moveB(220, false, true, 90, 900);

// left_motors.move(0);
// right_motors.move(0);
// extake();
// pros::delay(125);
// rest();


// //MIDDLE SCORE
// pros::delay(50);
// middleScore();
// pros::delay(2250);



// chassis.moveToPoint(-100, 22, 1000);
// rest();
// chassis.turnToHeading(5, 500);
// moveF(500, true, true, 85, 1200);


// chassis.turnToHeading(270, 500);
// doink.set_value(true);
// load();
// chassis.moveToPoint(-117, chassis.getPose().y, 1000, {.maxSpeed = 55,.minSpeed = 50});
// chassis.waitUntilDone();
// load();
// pros::delay(1500);




// chassis.moveToPoint(-82, chassis.getPose().y , 1200, {.forwards = false,  .maxSpeed = 80, .minSpeed = 40});
// chassis.waitUntil(25);
// unload();
// doink.set_value(false);
// pros::delay(2200);
// rest();
// chassis.moveToPose(-122, 0, 180, 1500, {.maxSpeed = 80, .minSpeed = 70});
// chassis.waitUntilDone();
// doink.set_value(true);
// wings.set_value(true);
// load();
// pros::delay(300);
// left_motors.move(100);
// right_motors.move(100);
// pros::delay(1250);
// left_motors.move(0);
// right_motors.move(0);
// moveF(1000, true, true, 60, 1000);
// }