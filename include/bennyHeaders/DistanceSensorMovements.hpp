#ifndef DISTANCE_SENSOR_MOVEMENTS_HPP
#define DISTANCE_SENSOR_MOVEMENTS_HPP

// Function declarations for distance sensor movements
void moveDualFront(double fLeftTarget, double fRightTarget,
                  bool forwards,
                  bool leftDecreasing, bool rightDecreasing,
                  int maxSpeed,
                  int timeOutMs,
                  bool holdHeading,
                  double desiredHeading);

void moveFR(double fTarget, double rTarget,
            bool forwards,
            bool frontDecreasing, bool rightDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading,
            double desiredHeading);

void moveFL(double fTarget, double lTarget,
            bool forwards,
            bool frontDecreasing, bool leftDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading,
            double desiredHeading);

void moveF(double fTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading,
           double desiredHeading);

void moveRL(double rTarget, double lTarget,
            bool forwards,
            bool rightDecreasing, bool leftDecreasing,
            int maxSpeed,
            int timeOutMs,
            bool holdHeading,
            double desiredHeading);

void moveR(double rTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading,
           double desiredHeading);

void moveL(double lTarget,
           bool forwards,
           bool decreasing,
           int maxSpeed,
           int timeOutMs,
           bool holdHeading,
           double desiredHeading);

#endif // DISTANCE_SENSOR_MOVEMENTS_HPP