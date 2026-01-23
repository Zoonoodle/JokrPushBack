#ifndef _PROS_ROBOT_CONFIGS_H_
#define _PROS_ROBOT_CONFIGS_H_

#include "main.h"
#include "lemlib/api.hpp"

//dt stuff
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;
extern lemlib::Chassis noOdomChassis;

//intake
extern pros::Motor intakeTop;
extern pros::Motor intakeBottom;
extern pros::Distance bottomDist;
extern pros::Distance backDist;
extern pros::Distance frontDist;

// Additional distance sensors

extern double distSensorOffsets[4]; //front, left, back, right offsets in inches

extern pros::Optical topOptical;
//tracking stuff
extern pros::Rotation vertical_encoder;
extern pros::Imu imu;
extern lemlib::TrackingWheel vertical;
extern lemlib::OdomSensors sensors;

//pneumatics
extern pros::adi::DigitalOut gate;
extern pros::adi::DigitalOut wings;
extern pros::adi::DigitalOut hoard;
extern pros::adi::DigitalOut doink;
extern pros::adi::DigitalOut park;
extern pros::adi::DigitalOut odomLift;




#endif