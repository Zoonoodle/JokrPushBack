
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
pros::Distance backDist(11);
pros::Distance frontDist(10);

// Additional distance sensors for new movement system
pros::Distance frontDistLeft(7);   // Adjust port numbers as needed
pros::Distance frontDistRight(8);  

pros::Distance leftDist(5);
pros::Optical topOptical(10);

// Distance sensor offsets in inches: front, left, back, right
double distSensorOffsets[4] = {4, 2, 1, 2};

//motors
pros::MotorGroup left_motors({-12, -13, 14}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({9, 16,-8}, pros::MotorGearset::blue);

pros::Motor intakeTop(-21, pros::MotorGearset::blue);
pros::Motor intakeBottom(-1, pros::MotorGearset::blue);

lemlib::TrackingWheel vertical(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0); // Adjust this offset based on your robot's geometry

//pneumatics
pros::adi::DigitalOut park('P');
pros::adi::DigitalOut wings('B');
pros::adi::DigitalOut hoard('A');
pros::adi::DigitalOut doink('D'); 
pros::adi::DigitalOut gate('P');
pros::adi::DigitalOut odomLift('P');

lemlib::ControllerSettings lateral(6.7, // proportional gain (kP)
    0, // integral gain (kI)
    27 , // derivative gain (kD)
    0, // anti windup
    .5, // small error range, in inches
    100, // small error range timeout, in milliseconds
    1, // large error range, in inches
    700, // large error range timeout, in milliseconds
    0);
  

										  
    lemlib::ControllerSettings angular(1.77, // proportional gain (kP)
      0, // integral gain (kI)
      12, // derivative gain (kD)
      0, // anti windup
      .5, // small error range, in inches
      150, // small error range timeout, in milliseconds
      3, // large error range, in inches
      600, // large error range timeout, in milliseconds
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
lemlib::OdomSensors noOdomSensors(nullptr, nullptr, nullptr, nullptr, &imu);


  
lemlib::Chassis chassis(drivetrain, lateral, angular, sensors, &throttle_curve, &steer_curve); 
lemlib:: Chassis noOdomChassis(drivetrain, lateral, angular, noOdomSensors, &throttle_curve, &steer_curve); 