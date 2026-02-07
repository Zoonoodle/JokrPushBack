#ifndef _PROS_ROBOT_CONFIGS_H_
#define _PROS_ROBOT_CONFIGS_H_

#include "main.h"
#include "lemlib/api.hpp"
#include "pros/rotation.hpp"

//dt stuff
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;
extern lemlib::Chassis noOdomChassis;

// Intake and Arm
extern pros::Motor intake;
extern pros::Motor arm;
extern pros::Rotation armRot;

// Distance sensors
extern pros::Distance rightDist;
extern pros::Distance leftDist;
extern pros::Distance backDist;
extern pros::Distance frontDist;

extern double distSensorOffsets[4]; //front, left, back, right offsets in inches

//tracking stuff
extern pros::Rotation vertical_encoder;
extern pros::Imu imu;
extern lemlib::TrackingWheel vertical;
extern lemlib::OdomSensors sensors;

// Pneumatics (5 total)
extern pros::adi::DigitalOut fourBar;
extern pros::adi::DigitalOut scraper;
extern pros::adi::DigitalOut intakeLift;
extern pros::adi::DigitalOut wing;
extern pros::adi::DigitalOut hoard;




#endif