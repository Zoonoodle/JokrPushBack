
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

lemlib::ControllerSettings lateral(7, // proportional gain (kP)
    0, // integral gain (kI)
    26 , // derivative gain (kD)
    0, // anti windup
    0.5, // small error range, in inches
    150, // small error range timeout, in milliseconds
    5, // large error range, in inches
    300, // large error range timeout, in milliseconds
    0);
  

										  
    lemlib::ControllerSettings angular(3.0, // proportional gain (kP)
      0, // integral gain (kI)
      14, // derivative gain (kD)
      0, // anti windup
      0.5, // small error range, in inches
      150, // small error range timeout, in milliseconds
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
