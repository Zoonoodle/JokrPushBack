#ifndef HARDWARE_AND_SENSORS_H
#define HARDWARE_AND_SENSORS_H

#include "main.h"
#include "pros/distance.hpp"
#include "pros/motors.hpp"
#include "pros/imu.hpp"

// Distance sensors
extern pros::Distance frontDistLeft;
extern pros::Distance frontDistRight;
extern pros::Distance rightDist;
extern pros::Distance leftDist;

// Motors (from robotConfigs.h)
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

// IMU
extern pros::Imu imu;

#endif // HARDWARE_AND_SENSORS_H