// #include "autons.h"
// #include "lemlib/chassis/chassis.hpp"
// #include "movement.h"
// #include "pros/abstract_motor.hpp"
// #include "pros/device.hpp"
// #include "pros/motors.h"
// #include "pros/rtos.hpp"
// #include "robotConfigs.h"
// #include "intakeControl.h"
// #include <ios>
// #include <utility>

// // TODO: All autonomous routines need to be rewritten for new robot hardware
// // New robot has: single intake motor, arm motor with PID, 5 pneumatics (fourBar, scraper, intakeLift, odomLift, hoard)
// void fourBallRight() {
//    chassis.moveToPoint(9, 26.5, 800);
// //  fourBar.set_value(true);
//  hoard.set_value(true);
//  intake.move(127);
//  pros::delay(100);
//  scraper.set_value(false);
//  chassis.swingToHeading(140, lemlib::DriveSide::RIGHT, 500);
 
// chassis.moveToPoint(32, 2, 800);
//  chassis.turnToHeading(180, 450);
// fourBar.set_value(false);
// scraper.set_value(true);

 
//  chassis.moveToPoint(chassis.getPose().x, 26, 700, {.forwards = false});
// chassis.waitUntilDone();
//  left_motors.move(-50);
//  right_motors.move(-80);
 
 
//  pros::delay(200);
//  hoard.set_value(false);
//  intake.move(127);
//  pros::delay(200);
 
//  arm.move(110);
//  pros::delay(200);
//  arm.move(-20);
//  pros::delay(75);
//  arm.move(90);
//  chassis.waitUntilDone();
//  intake.move(-127);
//  left_motors.move(0);
//  right_motors.move(0);
//  pros::delay(400);
//  scraper.set_value(true);
//  moveF(687, true, true, 70, 0, 600);
//  wing.set_value(false);
//  chassis.turnToHeading(-135, 450);
//  chassis.moveToPoint(47, 23, 700, {.forwards =false});
//  chassis.turnToHeading(-190, 500);
//  chassis.waitUntilDone();
//  chassis.moveToPoint(45, 41, 1500, {.forwards =false, .maxSpeed = 70});
//  wing.set_value(true);

// }
// void sixBallRight() {
//      // THIS IS THE  6 + 3 AUTO lATE WING
//  chassis.moveToPoint(9, 26.5, 800);
//  fourBar.set_value(true);
//  hoard.set_value(true);
//  intake.move(127);
//  pros::delay(100);
//  scraper.set_value(false);
//  chassis.moveToPose(34, 42, 70, 1800, {.lead = 0.6, .maxSpeed = 80, .minSpeed = 30});
//  pros::delay(300);
//  scraper.set_value(true);


// //  chassis.swingToHeading(-3, lemlib::DriveSide::RIGHT, 400, {.earlyExitRange = 5});
// chassis.moveToPoint(chassis.getPose().x -10, chassis.getPose().y -5, 500, {.forwards = false});
//  chassis.moveToPoint(18, 12, 1300, {.forwards = false, .maxSpeed = 80});

//  chassis.turnToHeading(-90, 600);
//  chassis.waitUntilDone();
//  moveB(445, true, false, 85, 0, 700);
//  chassis.turnToHeading(180, 500);
//  fourBar.set_value(false);
//  chassis.waitUntilDone();

//  scraper.set_value(false);
 
//  chassis.moveToPoint(chassis.getPose().x, 26, 700, {.forwards = false});
// chassis.waitUntilDone();
//  left_motors.move(-50);
//  right_motors.move(-80);
 
 
//  pros::delay(200);
//  hoard.set_value(false);
//  intake.move(127);
//  pros::delay(200);
 
//  arm.move(110);
//  pros::delay(200);
//  arm.move(-20);
//  pros::delay(75);
//  arm.move(90);
//  chassis.waitUntilDone();
//  intake.move(-127);
//  left_motors.move(0);
//  right_motors.move(0);
//  pros::delay(400);
//  scraper.set_value(true);
//  moveF(687, true, true, 70, 0, 600);
//  wing.set_value(false);
//  chassis.turnToHeading(-125, 450);
//  chassis.moveToPoint(47, 23, 700, {.forwards =false});
//  chassis.turnToHeading(-190, 500);
//  chassis.waitUntilDone();
//  chassis.moveToPoint(45, 41, 1500, {.forwards =false, .maxSpeed = 70});
//  wing.set_value(true);
// //  chassis.setPose(0,0,0);
 
// }
// void SigSawp() {
//     //start
//     wing.set_value(false);
//     pros::Task unjamTask(intakeUnjamTask);
//     fourBar.set_value(false);
//     //to loader
//     moveF(465, true, true, 70, 0, 1000);//was 460
//     //turn to loader
//     chassis.turnToHeading(91, 500);
//     pros::delay(100);
//     intake.move(127);
// scraper.set_value(false);
//     //into loader
//     chassis.moveToPoint(10.1, chassis.getPose().y, 1000, {.maxSpeed = 50  , .minSpeed = 45});//was y+1
//     chassis.waitUntilDone();
// //    left_motors.move(45);
// //    right_motors.move(45);
// // pros::delay(1300);
// fourBar.set_value(false);
// left_motors.move(35);
// right_motors.move(35);
// pros::delay(350);


//     //into goal
//     chassis.moveToPoint(-21,chassis.getPose().y+2, 1600, {.forwards = false, .maxSpeed = 85});
//     chassis.waitUntil(21);
//     hoard.set_value(false);
    
//     pros::delay(350);
//     arm.move(90);

//     chassis.waitUntilDone();
//     pros::delay(150);
//     scraper.set_value(true);
  
//     pros::delay(200);
//     intake.move(-127);
//     //turn off of goal
//     chassis.turnToHeading(205, 550);

//     pros::delay(100);
//     arm.move(-127);
 
//     //to cluster 1
//     chassis.moveToPoint(chassis.getPose().x -5, 7, 600, {.maxSpeed = 100, .earlyExitRange=  3});

//     scraper.set_value(false);
//     fourBar.set_value(true);
//     intake.move(127);
//     arm.move(-10);
//     hoard.set_value(true);
//     chassis.turnToHeading(175, 300);

//     chassis.moveToPoint(chassis.getPose().x, -35, 1000, {.minSpeed = 40});//was x+5
//     pros::delay(150);
//     scraper.set_value(true);
//     intake.move(-127);
    
//     pros::delay(100);
//     intake.move(127);
//     chassis.waitUntil(20);
//     scraper.set_value(false);
    

// intake.move(127);

// chassis.turnToHeading(120,  400);
// fourBar.set_value(false);
// chassis.moveToPoint(chassis.getPose().x+20, -60, 1000, {.maxSpeed = 80});


// intake.move(-127);
// pros::delay(150);
// intake.move(127);
// // scraper.set_value(true);
// intake.move(127);
// chassis.turnToHeading(86, 550);



// fourBar.set_value(false);
// chassis.moveToPoint(chassis.getPose().x-14, chassis.getPose().y, 1300, {.forwards = false, .maxSpeed = 90, .minSpeed = 50});

// left_motors.move(-80);
// right_motors.move(-50);


// pros::delay(200);
// hoard.set_value(false);
// intake.move(127);
// pros::delay(200);

// arm.move(110);
// pros::delay(200);
// arm.move(-20);
// pros::delay(75);
// arm.move(90);
// chassis.waitUntilDone();
// intake.move(-127);
// left_motors.move(0);
// right_motors.move(0);

// chassis.setPose(0,0,0);

// pros::delay(300);
// arm.move(-127);

// // chassis.moveToPoint(0, chassis.getPose().y, 500, {.maxSpeed = 65, .minSpeed = 60, .earlyExitRange = 5});
// scraper.set_value(false);
// chassis.moveToPoint(chassis.getPose().x-1, chassis.getPose().y+30, 1300, {.maxSpeed = 60, .minSpeed = 40});


// chassis.waitUntil(3);
// fourBar.set_value(true);
// intake.move(127);
// chassis.waitUntilDone();
// left_motors.move(35);
// right_motors.move(35);
// pros::delay(100);

// intake.move(127);

// hoard.set_value(true);

// chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 300);

// moveF(440, false, false, 70, 0, 1000);

// chassis.turnToHeading(50, 500);

// chassis.moveToPoint(chassis.getPose().x-30, chassis.getPose().y-30, 1600, {.forwards = false, .minSpeed = 50});




// // moveF(535 , false, false, 80, 0, 1000);
// //hassis.moveToPoint(chassis.getPose().x - 4, chassis.getPose().y, 600, {.forwards = false});

// // chassis.turnToHeading(140, 400);
// // chassis.waitUntilDone();
// // chassis.setPose(0,0,0);
// // chassis.moveToPoint(0, -32, 600, {.forwards = false, .earlyExitRange = 5});
// // chassis.moveToPoint(0,-47, 1800, {.forwards = false, .maxSpeed = 70, .minSpeed = 60});


// chassis.waitUntilDone();
// left_motors.move(-30);
// right_motors.move(-30);

// pros::delay(0);//for now
// hoard.set_value(false);

// arm.move(65);



// //  pros::delay(100);
 




// }










// void Low54() {
//     chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
//     //to first cluster
//    chassis.turnToHeading(19, 100);
//    chassis.moveToPoint(8,19, 1000, {.maxSpeed = 70});
//    intake.move(127);
//    hoard.set_value(true);
//    //grab first cluster
//    chassis.waitUntil(17);
//    scraper.set_value(true);
 
//    //to middle
//    chassis.turnToHeading(50, 500);
//    chassis.moveToPoint(30.5,40,1000, {.maxSpeed = 85});

//    scraper.set_value(false);
//     //to long
//      chassis.moveToPoint(15,11, 1200, {.forwards = false});
//      chassis.turnToHeading(270, 600);
//      fourBar.set_value(true);
//      moveB(450, false,true, 80, 0, 1500);
//      chassis.turnToHeading(179, 500);
//      chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 13, 500, {.forwards = false});
//      chassis.waitUntil(5);
//      hoard.set_value(false);
//      arm.move(127);

//      pros::delay(400);
//      intake.move(-127);
//      pros::delay(400);
//      arm.move(-100);
//      chassis.moveToPoint(chassis.getPose().x-.5, -12.5, 2000, {.maxSpeed = 55, .minSpeed = 50});
//      scraper.set_value(true);
//      pros::delay(600);
//      arm.move(-10);
//      intake.move(127);
//      chassis.waitUntilDone();
//      hoard.set_value(true);
//      left_motors.move(30);
//      right_motors.move(30);
//      pros::delay(500);
//     moveF(460, false, false, 50, 0, 1000);
//     scraper.set_value(false);
//      chassis.turnToHeading(-45, 700);
//      chassis.moveToPoint(-.5, 34, 1650, {.maxSpeed = 65});
// pros::delay(1500);

//      intake.move(-90);
//      chassis.waitUntilDone();
//      left_motors.move(-25);
//          right_motors.move(-25);
//          pros::delay(350);
//          left_motors.move(0);
//          right_motors.move(0);
//          intake.move(-90);
//          pros::delay(900);
//      chassis.moveToPoint(27, 6, 1500, {.forwards = false});
//      chassis.turnToHeading(0, 300);
//      wing.set_value(true);
//      chassis.moveToPoint(chassis.getPose().x, 38, 1000);
//      chassis.waitUntilDone();
//     chassis.turnToHeading(-15, 10000);
//      //28,8

    
//     // //to low
//     // chassis.moveToPoint(32, 13, 1000, {.forwards = false});
//     // chassis.turnToHeading(-47, 750);
//     // chassis.moveToPoint(-8, 46, 2000, {.maxSpeed = 100});
//     // chassis.waitUntilDone();
//     // intake.move(-127);

//     // //to wing
//     // pros::delay(500);
//     // intake.move(0);
//     // chassis.moveToPoint(12, 26, 1500, {.forwards = false, .maxSpeed = 100});
//     // chassis.turnToHeading(0, 300);
//     // wing.set_value(true);
//     // moveB(1000, true, false, 100, 50, 1000);
// }
// void High54() {
//     ////start 6 ball
//     fourBar.set_value(true);
//     hoard.set_value(true);
//     //to cluster
//     chassis.turnToHeading(-21, 300);
//     chassis.moveToPoint(-7, 17, 1200);
//     scraper.set_value(false);
//     intake.move(127);
//     hoard.set_value(true);
//     chassis.turnToHeading(-50, 300);
//     //to middle
//     chassis.moveToPoint(-28, 38.5, 1000);
//     scraper.set_value(true);
//     chassis.waitUntilDone();
    
//     //to goal
//     chassis.swingToHeading(-25, lemlib::DriveSide::RIGHT, 400);
//     chassis.moveToPoint(-16, 21, 1000, {.forwards = false});
//     scraper.set_value(false);
//     chassis.turnToHeading(205, 500);
//     fourBar.set_value(false);
//     wing.set_value(false);
//     chassis.moveToPoint(-22, 5, 1000);
//     chassis.turnToHeading(-87, 1000);
 
//     moveF(460, true, true, 70, 0, 600);
//     chassis.waitUntilDone();
//     chassis.turnToHeading(178, 750);
//     intake.move(0);
//     //into goal
//     chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y+10, 750, {.forwards = false});
//     chassis.waitUntilDone();
//     hoard.set_value(false);
//     intake.move(127);
//     arm.move(100);
//     left_motors.move(-70);
//     right_motors.move(-50);
//     /// end 6 ball
//     pros::delay(500);
//     left_motors.move(0);
//     right_motors.move(0);
//     pros::delay(100000);
//     chassis.moveToPoint(chassis.getPose().x-2, -10, 2000, {.maxSpeed = 60, .minSpeed = 40});
//     arm.move(-80);
//     intake.move(-127);
//     pros::delay(400);

//     pros::delay(100000);
//     fourBar.set_value(true);
//     intake.move(127);
// hoard.set_value(true);
//     arm.move(0);
//     chassis.waitUntilDone();
//     left_motors.move(35);
//     right_motors.move(35);
//     pros::delay(300);




// chassis.swingToHeading(185, lemlib::DriveSide::RIGHT, 300);
// moveF(420, false, false, 70, 0, 1000);

// chassis.turnToHeading(230, 500);

// chassis.moveToPoint(chassis.getPose().x+30, chassis.getPose().y+25, 1600, {.forwards = false, .minSpeed = 50});

// chassis.waitUntilDone();

// //back into mid
// left_motors.move(-35);
// right_motors.move(-35);

// //arm up
// arm.move(70);
// hoard.set_value(false);
// pros::delay(700);
// hoard.set_value(false);

// //arm down
// arm.move(-100);
// intake.move(-127);
// pros::delay(300);
// arm.move(0);
// intake.move(0);

// }

// void PIDtune() {
//     chassis.turnToHeading(90, 500);
//     chassis.turnToHeading(0, 600);
//     // chassis.setPose(0,0,0);
//     // chassis.moveToPoint(0, 24, 1200);
//     // chassis.moveToPoint(0, 0, 1200, {.forwards = false});
// }

// void elimsMidRush() {
//     chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
//     fourBar.set_value(true);
//     //to first cluster

// intake.move(127);
// chassis.turnToHeading(10, 150);

//    chassis.moveToPoint(8,18, 1200, {.maxSpeed = 75});

   
//    hoard.set_value(true);
//    //grab first cluster
//    chassis.waitUntil(10);
//     scraper.set_value(false);
 
//    //to middle
//    chassis.turnToHeading(50, 350);
//   pros::delay(200);
//   scraper.set_value(true);
//    chassis.moveToPoint(32,40.5, 1200, {.maxSpeed = 75});
  
//     //.back to low
//     chassis.moveToPoint(13, 20, 1000, {.forwards = false});
//     chassis.turnToHeading(-47, 600);
//     // fourBar.set_value(true);
//     //go to low
//     chassis.moveToPoint(-3, 35.5, 850, {.maxSpeed = 65});
//     pros::delay(400);
  
//          intake.move(-55);
//          intakeLift.set_value(true);
//          chassis.waitUntilDone();
//          fourBar.set_value(false);
//          left_motors.move(25);
//          right_motors.move(25);
//          pros::delay(350);
//          left_motors.move(0);
//          right_motors.move(0);
//          intake.move(-40);
//          pros::delay(900);
//     //go to matchload
//     chassis.moveToPoint(32, 0, 1200, {.forwards = false});
//     intakeLift.set_value(false);
  
//     intake.move(127);
//     chassis.turnToHeading(269, 500);
    
// fourBar.set_value(true);

//     chassis.waitUntilDone();
//     intake.move(0);
//     moveB(440, true, false, 70, 0, 700);

//     //turn to match
//     chassis.turnToHeading(178, 600);
//     scraper.set_value(false);

//     chassis.moveToPoint(chassis.getPose().x, -12, 950, {.maxSpeed = 45, .minSpeed = 45});
//         intake.move(127);
      
      
//         chassis.waitUntilDone();
//     left_motors.move(35);
//     right_motors.move(35);
//     pros::delay(260);

//     //move back
//     chassis.moveToPoint(chassis.getPose().x, -5, 700, {.forwards = false});
//     chassis.turnToHeading(-64, 500);
//     scraper.set_value(true);
    
//     //go to middle
//     chassis.moveToPoint(-34, 25, 2000, {.maxSpeed = 90});
//     chassis.turnToHeading(-138, 550);
//     chassis.moveToPoint(-26, 29.5, 1500, {.forwards = false, .maxSpeed = 55});
//     chassis.waitUntil(2);
//     hoard.set_value(false);
//     pros::delay(450);
//     arm.move(60);
//     chassis.waitUntilDone();
//     left_motors.move(-25);
//     right_motors.move(-25);

// }

// void sevenBall() {
    
// }

// void powerBeansAuto() {
//     // TODO: Rewrite for new robot
// }

// void SigSawp15Ball() {
//     intake.move(127);
//     hoard.set_value(true);
//   chassis.moveToPoint(0, 4, 500, {.minSpeed = 40});
//   fourBar.set_value(true);
//   chassis.turnToHeading(0, 200);
//   chassis.waitUntilDone();
//     moveB(470, true, false, 85, 0, 1400);
//     chassis.turnToHeading(-90, 400);
//     scraper.set_value(false);
// chassis.waitUntilDone();
//     chassis.moveToPoint(-10.25, chassis.getPose().y, 1000, {.maxSpeed = 45, .minSpeed = 40});
  
//     chassis.waitUntilDone();
//   chassis.waitUntilDone();
//     left_motors.move(35);
//     right_motors.move(35);
//     pros::delay(500);

//     chassis.moveToPoint(25.5, chassis.getPose().y -1, 1000, {.forwards = false, .maxSpeed = 70, .minSpeed = 45});
  
//     pros::delay(200);
//     fourBar.set_value(false);
//     chassis.waitUntil(18);
//     hoard.set_value(false);
    
//     pros::delay(400);
//     arm.move(100);
//     chassis.waitUntilDone();

    
//     intake.move(-127);


    
// 	double frontAvg = accumulateReading(frontDist, 100);
// 	double leftAvg  = accumulateReading(leftDist, 100);
  
// 	if (frontAvg > 0 && leftAvg > 0) {  // -1 means no valid readings
// 		chassis.setPose(-72 + (frontAvg / 25.4) + distSensorOffsets[0],
// 						-72 + (leftAvg / 25.4)  + distSensorOffsets[1],
// 						chassis.getPose().theta);
// 	} else {chassis.setPose(-28, -58, chassis.getPose().theta);}
    
  
//     pros::delay(400);
//     arm.move(-90);
//     scraper.set_value(true);
  
//     // chassis.moveToPoint(-46, -50, 700);
    
    
   
//     // chassis.turnToHeading(25, 550);
//     chassis.turnToHeading(10, 500);
//     chassis.waitUntilDone();
//     hoard.set_value(true);
//     arm.move(-20);
//     intake.move(127);
//     chassis.moveToPoint(-23.5, -26, 900, {.maxSpeed = 75});
//     pros::delay(300);
//     scraper.set_value(false);
//     chassis.turnToHeading(45, 450);
//         pros::delay(400);
//     scraper.set_value(true);
//     chassis.moveToPoint(-14.5, -13, 800, {.maxSpeed = 70});

//     arm.set_brake_mode(pros::MotorBrake::hold);
//     arm.move(10);
//     pros::delay(50);
//     arm.move(0);
//     chassis.waitUntilDone();
    
 
//         //after first goal

//     // moveF(500, true, true, 70, 0, 1000);
// //     chassis.turnToHeading(43.5, 700);
// //     chassis.waitUntilDone();
// //     intake.move(127);
// //     chassis.moveToPoint(44.5, -6, 2000, {.maxSpeed = 75});

//     //inside low goal
//     chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    
//     // intakeLift.set_value(true);
    
		
//         intake.move(-60);
//         left_motors.move(-15);
//         right_motors.move(-15);
//         pros::delay(700);
//         left_motors.move(-25);
//         right_motors.move(-25);
//         intake.move(-70);
//         pros::delay(300);
//     intakeLift.set_value(false);
//     chassis.moveToPoint(-31, -20, 700, {.forwards = false});
// pros::delay(20);
  
//     chassis.turnToHeading(0, 400);
//     intake.move(127);
//     chassis.moveToPoint(-30, 21, 900, {.maxSpeed = 105});
//     pros::delay(500);
    
//     scraper.set_value(false);
//     chassis.turnToHeading(-40, 300);
//     chassis.moveToPoint(-53.5, 45, 900, {.maxSpeed = 75});
//     chassis.turnToHeading(-90, 400);
//     // fourBar.set_value(true);
//     scraper.set_value(false);
//     chassis.waitUntilDone();

//     // pros::delay(150);
//     chassis.moveToPoint(chassis.getPose().x -13, chassis.getPose().y+.4, 800, {.maxSpeed = 45, .minSpeed = 40});

//     chassis.waitUntilDone();
//     left_motors.move(35);
//     right_motors.move(35);
//     pros::delay(200);
//     chassis.moveToPoint(-30, chassis.getPose().y, 1300, {.forwards = false, .maxSpeed = 90, .minSpeed = 45});
//     intake.move(127);
   
//     chassis.waitUntil(12);
//     fourBar.set_value(false);
//     pros::delay(100);
//     hoard.set_value(false);
    
//     pros::delay(100);
//     left_motors.move(-50);
//     right_motors.move(-50);
//     arm.move(110);
//     intake.move(-127);



// }

// void lateMidSawp() {
//     // TODO: Rewrite for new robot
// }

// void antiVitalityAuto() {
//  // THIS IS THE  6 + 3 AUTO lATE WING
//  chassis.moveToPoint(-9, 26.5, 800);
//  fourBar.set_value(true);
//  hoard.set_value(true);
//  intake.move(127);
//  pros::delay(100);
//  scraper.set_value(false);
//  chassis.moveToPose(-35, 45, -70, 1800, {.lead = 0.6, .maxSpeed = 80, .minSpeed = 30});
//  pros::delay(300);
//  scraper.set_value(true);


//  chassis.swingToHeading(3, lemlib::DriveSide::LEFT, 400, {.earlyExitRange = 5});

//  chassis.moveToPoint(-27, 12, 1500, {.forwards = false, .maxSpeed = 80});

//  chassis.turnToHeading(90, 600);
//  chassis.waitUntilDone();
//  moveB(445, true, false, 85, 0, 700);
//  chassis.turnToHeading(180, 500);
//  fourBar.set_value(false);
//  chassis.waitUntilDone();

//  scraper.set_value(false);
 
//  chassis.moveToPoint(chassis.getPose().x, 26, 700, {.forwards = false});
// chassis.waitUntilDone();
//  left_motors.move(-80);
//  right_motors.move(-50);
 
 
//  pros::delay(200);
//  hoard.set_value(false);
//  intake.move(127);
//  pros::delay(200);
 
//  arm.move(110);
//  pros::delay(200);
//  arm.move(-20);
//  pros::delay(75);
//  arm.move(90);
//  chassis.waitUntilDone();
//  intake.move(-127);
//  left_motors.move(0);
//  right_motors.move(0);
 
//  chassis.setPose(0,0,0);
 
//  pros::delay(300);
//  arm.move(-127);
 
//  // chassis.moveToPoint(0, chassis.getPose().y, 500, {.maxSpeed = 65, .minSpeed = 60, .earlyExitRange = 5});
//  scraper.set_value(false);
//  chassis.moveToPoint(chassis.getPose().x-1, chassis.getPose().y+30, 1100, {.maxSpeed = 60, .minSpeed = 40});
 
 
//  chassis.waitUntil(3);
//  fourBar.set_value(true);
//  intake.move(127);
//  chassis.waitUntilDone();
//  left_motors.move(35);
//  right_motors.move(35);
//  pros::delay(100);
 
//  intake.move(127);
 
//  hoard.set_value(true);
 
//  chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 300);
 
//  moveF(450, false, false, 70, 0, 1000);
 
//  chassis.turnToHeading(50, 500);
 
//  chassis.moveToPoint(chassis.getPose().x-29, chassis.getPose().y-29, 1600, {.forwards = false, .minSpeed = 50});
 
 
 
 
//  // moveF(535 , false, false, 80, 0, 1000);
//  //hassis.moveToPoint(chassis.getPose().x - 4, chassis.getPose().y, 600, {.forwards = false});
 
//  // chassis.turnToHeading(140, 400);
//  // chassis.waitUntilDone();
//  // chassis.setPose(0,0,0);
//  // chassis.moveToPoint(0, -32, 600, {.forwards = false, .earlyExitRange = 5});
//  // chassis.moveToPoint(0,-47, 1800, {.forwards = false, .maxSpeed = 70, .minSpeed = 60});

//  hoard.set_value(false);
//  chassis.waitUntilDone();
//  left_motors.move(-30);
//  right_motors.move(-30);
 
//  pros::delay(0);//for now

 
//  arm.move(65);
 
 
//  pros::delay(2500);
//  hoard.set_value(true);
// // chassis.moveToPoint(-21, 32, 1000);
// // fourBar.set_value(false);
// // chassis.turnToHeading(175, 550);
// // chassis.waitUntilDone();
// // chassis.moveToPoint(-24, 49, 1000, {.forwards = false});
// // chassis.waitUntil(10);
// // wing.set_value(true);

// // hoard.set_value(true);
// // chassis.moveToPose(-24.5, 40, 177, 1500, {.maxSpeed = 80, .minSpeed = 30});
// // pros::delay(300);
// // fourBar.set_value(false);
// //  chassis.moveToPoint(-19, 32, 700, {.forwards = false})
// }



// void leftSideNineBall() {
//     // TODO: Rewrite for new robot
// }

// void leftSide4ball() {
//     // TODO: Rewrite for new robot
//     fourBar.set_value(true);
//     moveF(415, true, true, 75, 0, 1000);
//     chassis.turnToHeading(270, 600);
    
//     intake.move(127);
// pros::delay(100);
// scraper.set_value(true);
//     chassis.moveToPoint(-10, chassis.getPose().y-.5, 1400, {.maxSpeed = 60, .minSpeed = 55});
//     chassis.waitUntilDone();
   
// left_motors.move(35);
// right_motors.move(35);
//     chassis.moveToPoint(22,chassis.getPose().y, 1600, {.forwards = false});
//     chassis.waitUntil(19);
//     hoard.set_value(false);
    
//     pros::delay(200);
// arm.move(100);

//     chassis.waitUntilDone();
//     scraper.set_value(false);
//     intake.move(-127);
//     pros::delay(300);
   

//     chassis.moveToPoint(chassis.getPose().x - 7,chassis.getPose().y, 500);
    

//     pros::delay(300);
//     arm.move(-10);
//     chassis.turnToHeading(-40, 400);
//     chassis.waitUntilDone();
//     chassis.moveToPoint(21, 20, 600, {.forwards = false});
//     chassis.turnToHeading(-95, 450);
//     chassis.waitUntilDone();
//     chassis.moveToPoint(40, 20.7, 1200, {.forwards = false, .maxSpeed = 90});
//     wing.set_value(true);
//     chassis.waitUntilDone();
//     pros::delay(2000);
//     chassis.turnToHeading(-80, 700);

// }
