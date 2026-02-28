
#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/imu.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"

pros::Rotation vertical_encoder(-6);
pros::Imu imu(18);

pros::Distance rightDist(21);
pros::Distance leftDist(11);
pros::Distance backDist(4);
pros::Distance frontDist(8);


// Additional distance sensors for new movement system
pros::Rotation armRot(-15);




// Distance sensor offsets in inches: front, left, back, right
double distSensorOffsets[4] = {4, 2, 1, 2};

//motors
pros::MotorGroup left_motors({-11, -14, -1}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({19, 7, 10}, pros::MotorGearset::blue);

pros::Motor intake(-3, pros::MotorGearset::blue);
pros::Motor arm(9, pros::MotorGearset::green);

lemlib::TrackingWheel vertical(&vertical_encoder, lemlib::Omniwheel::NEW_2, 0); // Adjust this offset based on your robot's geometry

// Pneumatics (5 total) - configure ports as needed
pros::adi::DigitalOut fourBar('D');      // fourBar solenoid
pros::adi::DigitalOut scraper('E');      // scraper
pros::adi::DigitalOut intakeLift('C');   // intake lift
pros::adi::DigitalOut wing('A');     // odom lift
pros::adi::DigitalOut hoard('B');        // hoard

lemlib::ControllerSettings angular(2.55  , // proportional gain (kP)
                                              0, // integral gain (kI)
                                              26, // derivative gain (kD)
                                              0, // anti windup
                                              0.75, // small error range, in inches
                                              150, // small error range timeout, in milliseconds
                                              4, // large error range, in inches
                                              700, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
lemlib::ControllerSettings lateral(6.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              20, // derivative gain (kD)
                                              0, // anti windup
                                              1.55, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              4.1, // large error range, in inches
                                              700, // large error range timeout, in milliseconds
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