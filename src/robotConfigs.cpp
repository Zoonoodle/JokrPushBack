
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

pros::Rotation vertical_encoder(-15);
pros::Imu imu(19);
pros::Distance bottomDist(4);
pros::Distance backDist(6);

// Additional distance sensors for new movement system
pros::Distance frontDistLeft(7);   // Adjust port numbers as needed
pros::Distance frontDistRight(8);  
pros::Distance rightDist(9);
pros::Distance leftDist(5);
pros::Optical topOptical(10);

//motors
pros::MotorGroup left_motors({-12, -13, 14}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({18, 16,-17}, pros::MotorGearset::blue);

pros::Motor intakeTop(-21, pros::MotorGearset::blue);
pros::Motor intakeBottom(-20, pros::MotorGearset::blue);

lemlib::TrackingWheel vertical(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0); // Adjust this offset based on your robot's geometry

//pneumatics
pros::adi::DigitalOut wings('E');
pros::adi::DigitalOut hoard('G');
pros::adi::DigitalOut doink('H');
pros::adi::DigitalOut park('D');

lemlib::ControllerSettings lateral(6.7, // proportional gain (kP)
    0, // integral gain (kI)
    27 , // derivative gain (kD)
    0, // anti windup
    .5, // small error range, in inches
    100, // small error range timeout, in milliseconds
    1, // large error range, in inches
    600, // large error range timeout, in milliseconds
    0);
  

										  
    lemlib::ControllerSettings angular(1.75, // proportional gain (kP)
      0, // integral gain (kI)
      12, // derivative gain (kD)
      0, // anti windup
      1, // small error range, in inches
      100, // small error range timeout, in milliseconds
      5, // large error range, in inches
      300, // large error range timeout, in milliseconds
      0 // maximum acceleration (slew)
);



lemlib::ExpoDriveCurve throttle_curve(3, 10, 1.009);
lemlib::ExpoDriveCurve steer_curve(5, 15, 1.021); // Less aggressive curve for steering



lemlib::Drivetrain drivetrain(&left_motors, 
							 &right_motors, 
							 11, 
							 lemlib::Omniwheel::NEW_325, 
							 450, 
							 8); //8 for traction 2 for omnis


lemlib::OdomSensors sensors(&vertical, nullptr, nullptr, nullptr, &imu);



  
lemlib::Chassis chassis(drivetrain, lateral, angular, sensors, &throttle_curve, &steer_curve); 
