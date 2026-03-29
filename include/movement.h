#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "pros/distance.hpp"

/**
 * @brief Move robot based on back distance sensor reading
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards
 * @param decreasing True if we want the distance reading to decrease (move closer to object), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param minSpeed Minimum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveB(double distance, bool forwards, bool decreasing, int maxSpeed, int minSpeed, int timeOutMs);

/**
 * @brief Move robot based on front distance sensor reading
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards
 * @param decreasing True if we want the distance reading to decrease (move closer to object), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param minSpeed Minimum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveF(double distance, bool forwards, bool decreasing, int maxSpeed, int minSpeed, int timeOutMs);

/**
 * @brief Time-based exponential decay drive - no odom dependency
 *
 * @param startSpeed Initial motor speed (0-127)
 * @param tau Decay time constant in ms - higher = slower decay
 * @param totalTime Total movement duration in ms
 * @param forwards True to drive forwards, false for reverse
 */
void driveExpo(double startSpeed, double tau, int totalTime, bool forwards = true);

/**
 * @brief Accumulate validated distance sensor readings over a time window
 *
 * @param sensor Reference to the distance sensor
 * @param ms Duration to accumulate readings in milliseconds
 * @param interval Delay between readings in milliseconds (default 20)
 * @return Average of valid readings in mm, or -1 if no valid readings
 */
double accumulateReading(pros::Distance& sensor, int ms, int interval = 20);

/**
 * @brief Correct odometry pose using distance sensors and wall math
 *
 * Pass expected sensor reading in mm for each sensor, or -1 to skip that sensor.
 * Front and back sensors can cross-check on the same axis for higher accuracy.
 *
 * @param frontExpMM Expected front sensor reading in mm (-1 to skip)
 * @param backExpMM Expected back sensor reading in mm (-1 to skip)
 * @param leftExpMM Expected left sensor reading in mm (-1 to skip)
 * @param tolMM Rejection tolerance — skip sensor if |actual - expected| exceeds this (default 50mm)
 * @param accumMs Duration to average sensor readings (default 80ms)
 */
void plannedReset(double frontExpMM = -1, double backExpMM = -1, double leftExpMM = -1,
                  double tolMM = 50, int accumMs = 80);

/**
 * @brief Move arm to a target position using PD control on the motor's IME
 *
 * Uses the integrated motor encoder for position feedback. The arm motor
 * must be tared (arm.tare_position()) at startup so positions are relative
 * to the starting "home" position.
 *
 * Usage examples:
 *   armTo(180, 127, 1000);       // fast start, PD slows near target, waits to settle
 *   armTo(180, 127, 500, 0);     // fast the entire way, exits as soon as it arrives
 *   armTo(180, 50, 2000);        // slow controlled move, gentle approach
 *   armTo(0, 100, 800);          // return to home position
 *
 * @param targetDeg Target position in degrees (from tared zero)
 * @param maxSpeed Maximum motor voltage (0-127)
 * @param timeOutMs Safety timeout in milliseconds
 * @param settleMs Time to hold within tolerance before exiting (0 = exit immediately on arrival)
 */
void armTo(double targetDeg, int maxSpeed = 127, int timeOutMs = 1000, int settleMs = 100);

#endif
