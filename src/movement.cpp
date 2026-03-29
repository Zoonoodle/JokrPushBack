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
void moveB(double distance, bool forwards, bool decreasing, int maxSpeed, int minSpeed, int timeOutMs) {
    // PID constants - tune these for optimal performance
    const double kP = 0.28;  // Proportional gain
    const double kD = 0.68;  // Derivative gain
    const double tolerance = 5;  // Distance tolerance in mm
    const int settleTime = 55;  // Time to stay within tolerance before exiting (ms)
    
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

        // If sensor returns a true error, stop
        if (currentDistance == PROS_ERR) {
            std::cout << "Back distance sensor error" << std::endl;
            break;
        }

        // If sensor reads out of range (9999), drive at max speed until in range
        if (currentDistance >= 9910) {
            int approachPower = forwards ? maxSpeed : -maxSpeed;
            left_motors.move(approachPower);
            right_motors.move(approachPower);
            prevError = 0;
            std::cout << "Back sensor out of range (" << currentDistance << "mm), driving at max speed" << std::endl;
            pros::delay(20);
            continue;
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
        int effectiveMinSpeed = (minSpeed > 0) ? minSpeed : 15;
        if (std::abs(motorPower) > 0 && std::abs(motorPower) < effectiveMinSpeed) {
            motorPower = (motorPower > 0) ? effectiveMinSpeed : -effectiveMinSpeed;
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
void moveF(double distance, bool forwards, bool decreasing, int maxSpeed, int minSpeed, int timeOutMs) {
    // PID constants - tune these for optimal performance
    const double kP = 0.28;  // Proportional gain
    const double kD = 0.69;  // Derivative gain
    const double tolerance = 2.5;  // Distance tolerance in mm
    const int settleTime = 55;  // Time to stay within tolerance before exiting (ms)
    
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

        // If sensor returns a true error, stop
        if (currentDistance == PROS_ERR) {
            std::cout << "Front distance sensor error" << std::endl;
            break;
        }

        // If sensor reads out of range (9999), drive at max speed until in range
        if (currentDistance >= 9910) {
            int approachPower = forwards ? maxSpeed : -maxSpeed;
            left_motors.move(approachPower);
            right_motors.move(approachPower);
            prevError = 0;
            std::cout << "Front sensor out of range (" << currentDistance << "mm), driving at max speed" << std::endl;
            pros::delay(20);
            continue;
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
        int effectiveMinSpeed = (minSpeed > 0) ? minSpeed : 15;
        if (std::abs(motorPower) > 0 && std::abs(motorPower) < effectiveMinSpeed) {
            motorPower = (motorPower > 0) ? effectiveMinSpeed : -effectiveMinSpeed;
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



void driveExpo(double startSpeed, double tau, int totalTime, bool forwards) {
    const int dt = 10;
    int dir = forwards ? 1 : -1;

    for (int t = 0; t < totalTime; t += dt) {
        int speed = (int)(startSpeed * exp(-(double)t / tau));
        if (speed < 3) speed = 0;
        left_motors.move(dir * speed);
        right_motors.move(dir * speed);
        pros::delay(dt);
    }

    left_motors.move(0);
    right_motors.move(0);
}

double accumulateReading(pros::Distance& sensor, int ms, int interval) {
    double sum = 0;
    int count = 0;
    int elapsed = 0;

    while (elapsed < ms) {
        int32_t reading = sensor.get();
        if (reading != PROS_ERR && reading <= 2000) {
            // For readings > 200mm, also require decent confidence
            if (reading <= 200 || sensor.get_confidence() >= 60) {
                sum += reading;
                count++;
            }
        }
        pros::delay(interval);
        elapsed += interval;
    }

    return (count > 0) ? (sum / count) : -1;
}

void plannedReset(double frontExpMM, double backExpMM, double leftExpMM,
                  double tolMM, int accumMs) {
    // Sensor offsets in inches (from distSensorOffsets[]: front=4, left=2, back=1)
    const double frontOffsetIn = distSensorOffsets[0]; // 4"
    const double backOffsetIn  = distSensorOffsets[2]; // 1"
    const double leftOffsetIn  = distSensorOffsets[1]; // 2"

    // Sensor robot-relative angles
    const double frontAngle = 0;
    const double backAngle  = 180;
    const double leftAngle  = 270;

    const double fieldHalf = 72.0; // half field in inches
    const double cardinalTol = 15.0; // max degrees off cardinal to accept
    const double crossCheckTol = 4.0; // inches tolerance for front+back cross-check
    const double mmToIn = 1.0 / 25.4;

    // --- Step 1: Accumulate all active sensors in parallel ---
    // Single loop reads all 3 sensors simultaneously
    double frontSum = 0, backSum = 0, leftSum = 0;
    int frontCount = 0, backCount = 0, leftCount = 0;
    int elapsed = 0;
    const int interval = 20;

    while (elapsed < accumMs) {
        if (frontExpMM >= 0) {
            int32_t r = frontDist.get();
            if (r != PROS_ERR && r <= 2000 && (r <= 200 || frontDist.get_confidence() >= 60)) {
                frontSum += r;
                frontCount++;
            }
        }
        if (backExpMM >= 0) {
            int32_t r = backDist.get();
            if (r != PROS_ERR && r <= 2000 && (r <= 200 || backDist.get_confidence() >= 60)) {
                backSum += r;
                backCount++;
            }
        }
        if (leftExpMM >= 0) {
            int32_t r = leftDist.get();
            if (r != PROS_ERR && r <= 2000 && (r <= 200 || leftDist.get_confidence() >= 60)) {
                leftSum += r;
                leftCount++;
            }
        }
        pros::delay(interval);
        elapsed += interval;
    }

    double frontActualMM = (frontCount > 0) ? (frontSum / frontCount) : -1;
    double backActualMM  = (backCount > 0)  ? (backSum / backCount)  : -1;
    double leftActualMM  = (leftCount > 0)  ? (leftSum / leftCount)  : -1;

    // --- Step 2: Validate each sensor against expected ---
    bool frontValid = (frontExpMM >= 0 && frontActualMM >= 0 &&
                       std::abs(frontActualMM - frontExpMM) <= tolMM);
    bool backValid  = (backExpMM >= 0 && backActualMM >= 0 &&
                       std::abs(backActualMM - backExpMM) <= tolMM);
    bool leftValid  = (leftExpMM >= 0 && leftActualMM >= 0 &&
                       std::abs(leftActualMM - leftExpMM) <= tolMM);

    double heading = chassis.getPose().theta;
    // Normalize heading to [0, 360)
    heading = fmod(heading, 360.0);
    if (heading < 0) heading += 360.0;

    // Helper: find nearest cardinal and check if within tolerance
    auto nearestCardinal = [&](double fieldAngle) -> int {
        // Returns cardinal (0/90/180/270) or -1 if too far off
        double cardinals[] = {0, 90, 180, 270, 360};
        for (double c : cardinals) {
            double diff = std::abs(fieldAngle - c);
            if (diff <= cardinalTol) return (int)fmod(c, 360);
        }
        return -1;
    };

    // Helper: compute position component from wall math
    // Returns {axis, value} where axis: 0=X, 1=Y, -1=invalid
    struct WallResult { int axis; double value; };
    auto wallMath = [&](double readingMM, double offsetIn, double sensorRobotAngle) -> WallResult {
        double fieldAngle = fmod(heading + sensorRobotAngle, 360.0);
        if (fieldAngle < 0) fieldAngle += 360.0;
        int cardinal = nearestCardinal(fieldAngle);
        if (cardinal < 0) return {-1, 0};

        double readingIn = readingMM * mmToIn;
        double distFromWall = readingIn + offsetIn;

        switch (cardinal) {
            case 0:   return {1,  fieldHalf - distFromWall};  // north wall -> Y
            case 90:  return {0,  fieldHalf - distFromWall};  // east wall -> X
            case 180: return {1, -fieldHalf + distFromWall};  // south wall -> Y
            case 270: return {0, -fieldHalf + distFromWall};  // west wall -> X
        }
        return {-1, 0};
    };

    // --- Step 3: Compute positions from valid sensors ---
    WallResult frontResult = {-1, 0};
    WallResult backResult  = {-1, 0};
    WallResult leftResult  = {-1, 0};

    if (frontValid) frontResult = wallMath(frontActualMM, frontOffsetIn, frontAngle);
    if (backValid)  backResult  = wallMath(backActualMM, backOffsetIn, backAngle);
    if (leftValid)  leftResult  = wallMath(leftActualMM, leftOffsetIn, leftAngle);

    lemlib::Pose pose = chassis.getPose();
    double newX = pose.x;
    double newY = pose.y;
    bool xSet = false, ySet = false;

    // --- Step 4: Handle front+back cross-check if both on same axis ---
    if (frontResult.axis >= 0 && backResult.axis >= 0 && frontResult.axis == backResult.axis) {
        double frontIn = frontActualMM * mmToIn + frontOffsetIn;
        double backIn  = backActualMM * mmToIn + backOffsetIn;
        double totalSpan = frontIn + backIn;

        if (std::abs(totalSpan - 144.0) <= crossCheckTol) {
            // Cross-check passes — average both positions
            double avg = (frontResult.value + backResult.value) / 2.0;
            if (frontResult.axis == 0) { newX = avg; xSet = true; }
            else                       { newY = avg; ySet = true; }
        } else {
            // Cross-check fails — use whichever was closer to its expected value
            double frontErr = std::abs(frontActualMM - frontExpMM);
            double backErr  = std::abs(backActualMM - backExpMM);
            WallResult& better = (frontErr <= backErr) ? frontResult : backResult;
            if (better.axis == 0) { newX = better.value; xSet = true; }
            else                  { newY = better.value; ySet = true; }
        }
    } else {
        // Front and back on different axes (or one/both invalid) — apply independently
        if (frontResult.axis == 0) { newX = frontResult.value; xSet = true; }
        else if (frontResult.axis == 1) { newY = frontResult.value; ySet = true; }

        if (backResult.axis == 0) { newX = backResult.value; xSet = true; }
        else if (backResult.axis == 1) { newY = backResult.value; ySet = true; }
    }

    // Apply left sensor result (always independent)
    if (leftResult.axis == 0) { newX = leftResult.value; xSet = true; }
    else if (leftResult.axis == 1) { newY = leftResult.value; ySet = true; }

    // --- Step 5: Apply corrected pose (keep heading from IMU) ---
    if (xSet || ySet) {
        chassis.setPose(newX, newY, pose.theta);
        std::cout << "plannedReset: pose -> (" << newX << ", " << newY << ", " << pose.theta << ")" << std::endl;
    } else {
        std::cout << "plannedReset: no valid sensors, pose unchanged" << std::endl;
    }
}

void armTo(double targetDeg, int maxSpeed, int timeOutMs, int settleMs) {
    // PD constants — tune these for your arm's weight/gearing
    const double kP = 1.5;   // Proportional gain
    const double kD = 0.12;  // Derivative gain
    const double tolerance = 5.0;  // Degrees — how close is "close enough"
    const int minSpeed = 15;       // Minimum power to overcome static friction / gravity

    // Stop any existing hold power, let the arm settle, then zero the encoder
    // so targetDeg is always relative to current position
    arm.move(0);
    pros::delay(50);
    arm.tare_position();

    double prevError = 0;
    uint32_t startTime = pros::millis();
    uint32_t settleStartTime = 0;
    bool isSettled = false;

    while (true) {
        if (pros::millis() - startTime > (uint32_t)timeOutMs) break;

        double current = arm.get_position();
        double error = targetDeg - current;

        // Settle detection
        if (std::abs(error) <= tolerance) {
            if (settleMs <= 0) break;  // No settle needed — exit immediately
            if (!isSettled) {
                settleStartTime = pros::millis();
                isSettled = true;
            } else if (pros::millis() - settleStartTime >= (uint32_t)settleMs) {
                break;  // Held within tolerance long enough
            }
        } else {
            isSettled = false;
        }

        // PD calculation
        double derivative = error - prevError;
        double power = (kP * error) + (kD * derivative);

        // Clamp to maxSpeed
        if (power > maxSpeed) power = maxSpeed;
        else if (power < -maxSpeed) power = -maxSpeed;

        // Apply minimum power to overcome friction (skip if error is tiny)
        if (std::abs(error) > tolerance && std::abs(power) < minSpeed) {
            power = (power > 0) ? minSpeed : -minSpeed;
        }

        arm.move((int)power);
        prevError = error;

        std::cout << "Arm: " << current << "deg, Target: " << targetDeg
                  << ", Error: " << error << ", Power: " << (int)power << std::endl;

        pros::delay(10);
    }

    // Hold position when done
    arm.set_brake_mode(pros::MotorBrake::hold);
    arm.move(0);

    std::cout << "armTo complete — final pos: " << arm.get_position() << "deg" << std::endl;
}

// GPS System, only run in newer autons where GPS is specified or used. 0,0 will be defined as the center of the field,
// and theta = 0 will be defined as a straight line from 0,0 to the center of the blue park zone
 void locateGPS(pros::Distance xDist, 
    pros::Distance yDist, 
    int offsetX,
    int offsetY,
    int xSign,//-1 or 1
    int ySign,//-1 or 1
    int rounds){
    //initialize variables
    double xAvgMM = 0, yAvgMM = 0, xAvgIn = 0, yAvgIn = 0;
    //first, find the average of the sensor readings because there is some noise
    for (int i = 0; i <= rounds; i++){
        xAvgMM += xDist.get();
        yAvgMM += yDist.get();
        pros::delay(10); //save the poor cpu
    }
    //Now that we have a ton of sensor readings, we can find the average
    xAvgMM /= rounds;
    yAvgMM /= rounds;
    //convert everything to inches because distance sensors are in millimeters and add the offsets
    xAvgIn = (xAvgMM / 25.4) + offsetX;
    yAvgIn = (yAvgMM / 25.4) + offsetY;
    //now, we can set pose to the new position
    chassis.setPose(xSign*(72 -xAvgIn), ySign*(72-yAvgIn), chassis.getPose().theta);

    
 }