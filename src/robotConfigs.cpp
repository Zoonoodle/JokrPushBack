
#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

pros::Rotation horizontal_encoder(7);
pros::Rotation vertical_encoder(9);
pros::Imu imu(7);

pros::Distance rightDist(6);
pros::Distance leftDist(5);
pros::Distance backDist(4);
pros::Distance frontDist(3);




// Distance sensor offsets in inches: front, left, back, right
double distSensorOffsets[4] = {5, 2, 1, 2};

//motors
pros::MotorGroup left_motors({-21, -16, -14}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({10, 15, 13}, pros::MotorGearset::blue);
pros::MotorGroup sharedMotors({-12, 11}, pros::MotorGearset::green);

// Stub motors on the same ports as sharedMotors — only here so autons/skills compile.
// Opcontrol uses sharedMotors + pto instead.
pros::Motor intake(12, pros::MotorGearset::green);
pros::Motor arm(11, pros::MotorGearset::green);

lemlib::TrackingWheel vertical(&vertical_encoder, lemlib::Omniwheel::NEW_2, -.25); // Adjust this offset based on your robot's geometry
lemlib::TrackingWheel horizontal(&horizontal_encoder, lemlib::Omniwheel::NEW_275_HALF, -5.5);
// Pneumatics (5 total) - configure ports as needed
pros::adi::DigitalOut fourBar('G');      // fourBar solenoid
pros::adi::DigitalOut scraper('B');      // scraper
pros::adi::DigitalOut intakeLift('C');   // intake lift
pros::adi::DigitalOut wing('A');     // odom lift
pros::adi::DigitalOut hoard('F');        // hoard
pros::adi::DigitalOut pto('D');

lemlib::ControllerSettings angular(2  , // proportional gain (kP)
                                              0, // integral gain (kI)
                                              22, // derivative gain (kD)
                                              0, // anti windup
                                              .5, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              6, // large error range, in inches
                                              600, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
lemlib::ControllerSettings lateral(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              18, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              4, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::ExpoDriveCurve throttle_curve(3, 10, 1.009);
lemlib::ExpoDriveCurve steer_curve(5, 15, 1.021); // Less aggressive curve for steering



lemlib::Drivetrain drivetrain(&left_motors, 
							 &right_motors, 
							 10.5, 
							 lemlib::Omniwheel::NEW_325, 
							 450, 
							 8); //8 for traction 2 for omnis


lemlib::OdomSensors sensors(&vertical, nullptr, nullptr, nullptr, &imu);
lemlib::OdomSensors noOdomSensors(nullptr, nullptr, nullptr, nullptr, &imu);


  
lemlib::Chassis chassis(drivetrain, lateral, angular, sensors, &throttle_curve, &steer_curve); 
lemlib:: Chassis noOdomChassis(drivetrain, lateral, angular, noOdomSensors, &throttle_curve, &steer_curve); 