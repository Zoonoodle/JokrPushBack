#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

/**
 * @brief Move robot based on back distance sensor reading
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards
 * @param decreasing True if we want the distance reading to decrease (move closer to object), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveB(double distance, bool forwards, bool decreasing, int maxSpeed, int timeOutMs);

/**
 * @brief Move robot based on front distance sensor reading
 * 
 * @param distance Target distance in millimeters that the sensor should read
 * @param forwards True to move forwards, false to move backwards
 * @param decreasing True if we want the distance reading to decrease (move closer to object), false to increase (move away)
 * @param maxSpeed Maximum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 */
void moveF(double distance, bool forwards, bool decreasing, int maxSpeed, int timeOutMs);

#endif
