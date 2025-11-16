#include "autons.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/device.hpp"
#include "robotConfigs.h"
#include "intakeControl.h"


void skillsOwen(){
chassis.setPose(0,-1,0);
    moveF(495, true, true, 75, 1200);
    load();
    chassis.turnToHeading(90, 500);
    doink.set_value(true);
    
    
        
    chassis.moveToPoint(11,chassis.getPose().y,1500, {.maxSpeed = 60,.minSpeed = 55});
    chassis.waitUntilDone();
    left_motors.move(30);
    right_motors.move(30);
    pros::delay(1000);
    left_motors.move(0);
    right_motors.move(0);
    
    chassis.moveToPoint(-22,chassis.getPose().y+.5,1350,{.forwards = false, .minSpeed = 40});
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
    chassis.moveToPoint(-29.5, 0, 1500, {.maxSpeed = 60});
    chassis.waitUntil(27);
    doink.set_value(true);
    
    chassis.turnToHeading(234, 400);
    chassis.moveToPoint(-6.7, 29, 1000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    doink.set_value(false);
    chassis.moveToPoint(-22,30,1000,{.forwards = false, .minSpeed = 40});
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
chassis.moveToPoint(-27, 7, 600, {.earlyExitRange = 8});

chassis.swingToHeading(270,DriveSide::RIGHT,500, {.earlyExitRange = 8});
extake();
pros::delay(80);
rest();
chassis.moveToPoint(-60, 7.5, 600, {.earlyExitRange = 10});
rest();
chassis.moveToPoint(-82, 8, 1000, {.maxSpeed = 85});
load();
chassis.waitUntil(12);
doink.set_value(true);
chassis.turnToHeading(270, 400);
chassis.waitUntilDone();
moveF(1135, false, false, 110, 700);
chassis.turnToHeading(320, 550);
rest();

// chassis.moveToPoint(-64.2, -7, 1800, {.forwards = false, .maxSpeed = 70});

chassis.waitUntilDone();
extake();
pros::delay(125);
rest();


rest();

//MIDDLE SCORE
moveB(250, false, true, 100, 750);

middleScore();
moveB(220, false, true, 75, 600);

pros::delay(550);
extake();
pros::delay(125);
middleScore();


pros::delay(1100);



doink.set_value(false);
chassis.moveToPoint(-100, 22, 1000);

chassis.turnToHeading(0, 500);
rest();
chassis.waitUntilDone();

moveF(495, true, true, 85, 1200);

chassis.turnToHeading(270, 500);
doink.set_value(true);
chassis.moveToPoint(-117, chassis.getPose().y-.25, 1000, {.maxSpeed = 60,.minSpeed = 60});
load();
chassis.waitUntilDone();

left_motors.move(30);
right_motors.move(30);
pros::delay(1200);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-82, chassis.getPose().y, 1200, {.forwards = false,  .maxSpeed = 80, .minSpeed = 40});
chassis.waitUntil(23.5);
unload();
doink.set_value(false);

chassis.waitUntilDone();
pros::delay(500);
extake();
pros::delay(120);
unload();
pros::delay(1000);


chassis.moveToPoint(chassis.getPose().x - 12.5, chassis.getPose().y, 800);
chassis.turnToHeading(180, 450);
rest();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

chassis.moveToPoint(chassis.getPose().x-.5, chassis.getPose().y-90, 2000);
chassis.waitUntilDone();
chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);


chassis.turnToHeading(183, 350);
chassis.waitUntilDone();
moveF(510, true, true, 75, 1200);
chassis.turnToHeading(272, 600);
doink.set_value(true);
load();
chassis.moveToPoint(-116.5, chassis.getPose().y+.5, 1200, {.maxSpeed = 60,.minSpeed = 50});
chassis.waitUntilDone();

left_motors.move(50);
right_motors.move(50);
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
chassis.moveToPoint(-79, chassis.getPose().y + 26, 1200, {.maxSpeed = 60});
chassis.waitUntil(18);
doink.set_value(true);
chassis.waitUntilDone();


chassis.moveToPoint(-100, chassis.getPose().y - 24, 1200, {.forwards = false});
chassis.waitUntilDone();

chassis.turnToHeading(270, 800);
chassis.waitUntilDone();

chassis.moveToPoint(-83, chassis.getPose().y-.1, 1000, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(15);
unload();
doink.set_value(false);
pros::delay(1100);

chassis.moveToPoint(chassis.getPose().x - 15, chassis.getPose().y, 800);

chassis.turnToHeading(35, 450);
chassis.moveToPoint(-68, chassis.getPose().y +28, 600, {.earlyExitRange = 10});
chassis.turnToHeading(100, 400);
chassis.moveToPoint(-44, -56, 800, {.earlyExitRange = 10});
chassis.moveToPoint(-10, -56, 800);
chassis.turnToHeading(180, 500);
chassis.waitUntilDone();
moveF(495, true, true, 75, 1300);
chassis.turnToHeading(90, 500);
doink.set_value(true);
load();

    
chassis.moveToPoint(12,chassis.getPose().y ,1300, {.maxSpeed = 60,.minSpeed = 60});
chassis.waitUntilDone();
left_motors.move(50);
right_motors.move(50);
pros::delay(1300);
left_motors.move(0);
right_motors.move(0);

chassis.moveToPoint(-24.5, chassis.getPose().y, 1250, {.forwards = false, .minSpeed = 40});
chassis.waitUntil(23);
unload();

chassis.waitUntilDone();
pros::delay(1400);

doink.set_value(false);


chassis.moveToPoint(12, -56.5, 700);
chassis.turnToHeading(9, 550);
// extake();
// chassis.moveToPoint(17, -23.5, 2000, {.maxSpeed = 90, .minSpeed = 90, .earlyExitRange = 5});


chassis.waitUntilDone();
// odomLift.set_value(true);
// noOdomChassis.setPose(0,0,0);

// extake();
chassis.moveToPoint(17, -23.5, 2000, {.maxSpeed = 80, .minSpeed = 80, .earlyExitRange = 5});// while(frontDist.get() > 1700 ){pros::delay(50);}
// noOdomChassis.waitUntil(22);
extake();

// while(true){
//     left_motors.move(0);
//     right_motors.move(0);
//     nochassis.moveT
//     pros::delay(50);
// }
//placeholder for distance sensor
}   

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