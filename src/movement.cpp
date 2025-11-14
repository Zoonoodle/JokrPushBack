#include "movement.h"
#include "robotConfigs.h"
#include "pros/rtos.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Move robot based on back distance sensor reading
 * 
 * This function uses a PID-like control loop to move the robot until the back distance
 * sensor reads the target distance. The robot will move forwards or backwards based on
 * the parameters, adjusting speed based on error from the target distance.
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards  
 * @param decreasing True if we want the distance reading to decrease (move closer), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveB(double distance, bool forwards, bool decreasing, int maxSpeed, int timeOutMs) {
    // PID constants - tune these for optimal performance
    const double kP = 0.2;
    const double kD = 0.525;   // Derivative gain
    const double tolerance = 7.0;  // Distance tolerance in mm
    const int settleTime = 100;  // Time to stay within tolerance before exiting (ms)
    
    // Error tracking
    double prevError = 0;
    double error = 0;
    uint32_t startTime = pros::millis();
    uint32_t settleStartTime = 0;
    bool isSettled = false;
    
    while (true) {
        // Check timeout
        if (pros::millis() - startTime > timeOutMs) {
            break;
        }
        
        // Read current distance from back sensor
        int32_t currentDistance = backDist.get();
        
        // If sensor returns error or max reading, stop
        if (currentDistance == PROS_ERR || currentDistance >= 9999) {
            std::cout << "Distance sensor error or no object detected" << std::endl;
            break;
        }
        
        // Calculate error based on whether we want distance to decrease or increase
        if (decreasing) {
            error = currentDistance - distance;  // Positive error means we need to move closer
        } else {
            error = distance - currentDistance;  // Positive error means we need to move away
        }
        
        // Check if we're within tolerance
        if (std::abs(error) <= tolerance) {
            if (!isSettled) {
                settleStartTime = pros::millis();
                isSettled = true;
            } else if (pros::millis() - settleStartTime >= settleTime) {
                // Successfully settled at target distance
                break;
            }
        } else {
            isSettled = false;
        }
        
        // Calculate derivative
        double derivative = error - prevError;
        
        // Calculate motor power using PD control
        double motorPower = (kP * error) + (kD * derivative);
        
        // Clamp motor power to maxSpeed
        if (motorPower > maxSpeed) {
            motorPower = maxSpeed;
        } else if (motorPower < -maxSpeed) {
            motorPower = -maxSpeed;
        }
        
        // Apply minimum power threshold to overcome static friction
        const int minPower = 15;
        if (std::abs(motorPower) > 0 && std::abs(motorPower) < minPower) {
            motorPower = (motorPower > 0) ? minPower : -minPower;
        }
        
        // Determine motor direction based on forwards parameter
        // If forwards is true and we have positive error (need to move), motors go forward
        // If forwards is false, invert the motor power
        int finalMotorPower = forwards ? motorPower : -motorPower;
        
        // Move motors
        left_motors.move(finalMotorPower);
        right_motors.move(finalMotorPower);
        
        // Update previous error for next iteration
        prevError = error;
        
        // Debug output
        std::cout << "Distance: " << currentDistance << "mm, Target: " << distance 
                  << "mm, Error: " << error << "mm, Power: " << finalMotorPower << std::endl;
        
        // Small delay for loop timing
        pros::delay(20);
    }
    
    // Stop motors when done
    left_motors.move(0);
    right_motors.move(0);
    
    std::cout << "moveB complete" << std::endl;
}

/**
 * @brief Move robot based on front distance sensor reading
 * 
 * This function uses a PD control loop to move the robot until the front distance
 * sensor reads the target distance. The robot will move forwards or backwards based on
 * the parameters, adjusting speed based on error from the target distance.
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards  
 * @param decreasing True if we want the distance reading to decrease (move closer), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveF(double distance, bool forwards, bool decreasing, int maxSpeed, int timeOutMs) {
    // PID constants - tune these for optimal performance
    const double kP = 0.2;  // Proportional gain
    const double kD = 0.5;  // Derivative gain
    const double tolerance = 7.0;  // Distance tolerance in mm
    const int settleTime = 100;  // Time to stay within tolerance before exiting (ms)
    
    // Error tracking
    double prevError = 0;
    double error = 0;
    uint32_t startTime = pros::millis();
    uint32_t settleStartTime = 0;
    bool isSettled = false;
    
    while (true) {
        // Check timeout
        if (pros::millis() - startTime > timeOutMs) {
            break;
        }
        
        // Read current distance from front sensor
        int32_t currentDistance = frontDist.get();
        
        // If sensor returns error or max reading, stop
        if (currentDistance == PROS_ERR || currentDistance >= 9999) {
            std::cout << "Front distance sensor error or no object detected" << std::endl;
            break;
        }
        
        // Calculate error based on whether we want distance to decrease or increase
        if (decreasing) {
            error = currentDistance - distance;  // Positive error means we need to move closer
        } else {
            error = distance - currentDistance;  // Positive error means we need to move away
        }
        
        // Check if we're within tolerance
        if (std::abs(error) <= tolerance) {
            if (!isSettled) {
                settleStartTime = pros::millis();
                isSettled = true;
            } else if (pros::millis() - settleStartTime >= settleTime) {
                // Successfully settled at target distance
                break;
            }
        } else {
            isSettled = false;
        }
        
        // Calculate derivative
        double derivative = error - prevError;
        
        // Calculate motor power using PD control
        double motorPower = (kP * error) + (kD * derivative);
        
        // Clamp motor power to maxSpeed
        if (motorPower > maxSpeed) {
            motorPower = maxSpeed;
        } else if (motorPower < -maxSpeed) {
            motorPower = -maxSpeed;
        }
        
        // Apply minimum power threshold to overcome static friction
        const int minPower = 15;
        if (std::abs(motorPower) > 0 && std::abs(motorPower) < minPower) {
            motorPower = (motorPower > 0) ? minPower : -minPower;
        }
        
        // Determine motor direction based on forwards parameter
        // If forwards is true and we have positive error (need to move), motors go forward
        // If forwards is false, invert the motor power
        int finalMotorPower = forwards ? motorPower : -motorPower;
        
        // Move motors
        left_motors.move(finalMotorPower);
        right_motors.move(finalMotorPower);
        
        // Update previous error for next iteration
        prevError = error;
        
        // Debug output
        std::cout << "Front Distance: " << currentDistance << "mm, Target: " << distance 
                  << "mm, Error: " << error << "mm, Power: " << finalMotorPower << std::endl;
        
        // Small delay for loop timing
        pros::delay(20);
    }
    
    // Stop motors when done
    left_motors.move(0);
    right_motors.move(0);
    
    std::cout << "moveF complete" << std::endl;
}
