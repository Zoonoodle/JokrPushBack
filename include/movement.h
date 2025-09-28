#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

/**
 * @brief Move using dual front distance sensors for alignment
 * @param fLeftTarget Target distance for front left sensor (mm)
 * @param fRightTarget Target distance for front right sensor (mm)
 * @param forwards True for forward movement, false for backward
 * @param leftDecreasing True if left sensor should decrease to target
 * @param rightDecreasing True if right sensor should decrease to target
 * @param maxSpeed Maximum motor speed (0-127)
 * @param timeOutMs Timeout in milliseconds
 * @param holdHeading Whether to hold a specific heading
 * @param desiredHeading Target heading in degrees (0-360)
 */
void moveDualFront(double fLeftTarget, double fRightTarget,
                  bool forwards,
                  bool leftDecreasing, bool rightDecreasing,
                  int maxSpeed,
                  int timeOutMs,
                  bool holdHeading = false,
                  double desiredHeading = 0.0);

/**
 * @brief Move using front right and right distance sensors
 */
void moveFR(double fTarget, double rTarget,
            bool forwards,
            bool frontDecreasing, bool rightDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading = false,
            double desiredHeading = 0.0);

/**
 * @brief Move using front left and left distance sensors
 */
void moveFL(double fTarget, double lTarget,
            bool forwards,
            bool frontDecreasing, bool leftDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading = false,
            double desiredHeading = 0.0);

/**
 * @brief Move using average of both front sensors
 */
void moveF(double fTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading = false,
           double desiredHeading = 0.0);

/**
 * @brief Move using right and left distance sensors
 */
void moveRL(double rTarget, double lTarget,
            bool forwards,
            bool rightDecreasing, bool leftDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading = false,
            double desiredHeading = 0.0);

/**
 * @brief Move using right distance sensor only
 */
void moveR(double rTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading = false,
           double desiredHeading = 0.0);

/**
 * @brief Move using left distance sensor only
 */
void moveL(double lTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading = false,
           double desiredHeading = 0.0);

/**
 * @brief Move using back distance sensor
 */
void moveB(double bTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading = false,
           double desiredHeading = 0.0);

#endif // _MOVEMENT_H_