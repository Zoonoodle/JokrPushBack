#include "intakeControl.h"
#include "robotConfigs.h"
bool isDone;
bool intakeOn;
bool gatePressed = false;
bool unjamEnabled = true;  // Flag to enable/disable unjam feature (default enabled)

// Global variables for jam detection
int savedBottomSpeed = 0;
int savedTopSpeed = 0;
int lastUnjamTime = 0;
int stallStartTime = 0;
bool currentlyStalled = false;

// Unjam task - ONLY monitors bottom intake for true jams
// Top intake is designed to jam on purpose for ball control
// Only triggers unjam when bottom intake is truly stuck (not just slow)
pros::Task* unjam_task = new pros::Task([]() {
    const int STALL_VELOCITY_THRESHOLD = 5;  // RPM - motor essentially stopped
    const int STALL_TIME_MS = 300;  // Must be stalled for 300ms continuously
    const int UNJAM_COOLDOWN_MS = 2000;  // 2 second cooldown between unjams
    const int MIN_VOLTAGE_THRESHOLD = 6000;  // Only check if commanding significant movement (mV)
    
    // Run continuously
    while (true) {
        // Only check for jams when unjam is enabled AND intake is running
        if (unjamEnabled && intakeOn) {
            // Get current bottom motor velocity (absolute value)
            double bottomVel = std::abs(intakeBottom.get_actual_velocity());
            
            // Get commanded voltage/power for bottom motor
            // Note: Since we use .move() not .move_velocity(), check voltage instead
            int32_t bottomVoltage = std::abs(intakeBottom.get_voltage());
            
            // Only check for jam if we're commanding significant movement
            // 6000mV = about 50% power (127 * 12V / 2 = ~6V)
            if (bottomVoltage > MIN_VOLTAGE_THRESHOLD) {
                // Check if motor is essentially stopped (true jam)
                bool isStalled = bottomVel < STALL_VELOCITY_THRESHOLD;
                
                if (isStalled) {
                    // Track how long we've been stalled
                    if (!currentlyStalled) {
                        // Just started stalling
                        currentlyStalled = true;
                        stallStartTime = pros::millis();
                    } else {
                        // Check if we've been stalled long enough
                        int stallDuration = pros::millis() - stallStartTime;
                        
                        if (stallDuration > STALL_TIME_MS) {
                            // Check cooldown
                            int currentTime = pros::millis();
                            bool canUnjam = (currentTime - lastUnjamTime) > UNJAM_COOLDOWN_MS;
                            
                            if (canUnjam) {
                                // Save current motor voltage (since we use .move(), not .move_velocity())
                                savedBottomSpeed = intakeBottom.get_voltage() / 12000.0 * 127.0;  // Convert mV to -127..127
                                savedTopSpeed = intakeTop.get_voltage() / 12000.0 * 127.0;
                                
                                // ONLY reverse bottom motor to unjam
                                // Top motor continues normal operation
                                intakeBottom.move(-127);
                                pros::delay(200);  // Brief reverse
                                
                                // Restore previous bottom speed
                                intakeBottom.move(savedBottomSpeed);
                                
                                // Update last unjam time
                                lastUnjamTime = currentTime;
                                currentlyStalled = false;
                                
                                // Small delay before checking again
                                pros::delay(100);
                            }
                        }
                    }
                } else {
                    // Not stalled anymore
                    currentlyStalled = false;
                }
            } else {
                // Not commanding movement, reset stall tracking
                currentlyStalled = false;
            }
        } else {
            // Unjam disabled or intake off, reset stall tracking
            currentlyStalled = false;
        }
        
        // Check every 20ms
        pros::delay(20);
    }
});



pros::Task* doublePark = new pros::Task([]() {
    while(true) {
        // Wait until sensor detects object (distance <= 38)
        while(bottomDist.get() > 38) {
            pros::delay(10);
        }
        
        // Object detected, activate gate
        gate.set_value(true);
        gatePressed = true;
        
        // Suspend task until next activation
        pros::Task::current().suspend();
    }
});



bool secondStageCounted(int count, int timeoutMs) {
    int currentCount = 0;
    int startTime = pros::millis();
    isDone = false;
    
    // Threshold values - adjust based on testing
    // Note: Optical sensor uses proximity - higher values mean closer
    const int BALL_PRESENT_THRESHOLD = 100;  // Proximity when ball is present (higher values)
    const int BALL_ABSENT_THRESHOLD = 50;    // Proximity when no ball (lower values)
    const int DEBOUNCE_MS = 50;  // Minimum time for stable reading
    const int SAMPLE_DELAY = 5;  // Delay between sensor samples
    
    // State tracking for edge detection
    bool ballWasPresent = false;
    int lastStateChangeTime = pros::millis();
    
    while (currentCount < count) {
        // Check for timeout
        if (pros::millis() - startTime > timeoutMs) {
            isDone = true;
            return false;  // Timeout - balls didn't exit in time
        }
        
        // Get current sensor reading
        int currentReading = topOptical.get_proximity();
        bool ballIsPresent = currentReading > BALL_ABSENT_THRESHOLD;
        
        // Debounce check - ensure stable reading for DEBOUNCE_MS
        if (ballIsPresent != ballWasPresent) {
            // State might be changing, wait for stable reading
            int stableReadingStart = pros::millis();
            bool isStable = true;
            
            while (pros::millis() - stableReadingStart < DEBOUNCE_MS) {
                if (pros::millis() - startTime > timeoutMs) {
                    isDone = true;
                    return false;  // Timeout during debounce
                }
                
                int newReading = topOptical.get_proximity();
                bool newBallPresent = newReading > BALL_ABSENT_THRESHOLD;
                
                if (newBallPresent != ballIsPresent) {
                    // Reading changed during debounce period, restart
                    isStable = false;
                    break;
                }
                
                pros::delay(SAMPLE_DELAY);
            }
            
            if (isStable) {
                // Stable state change detected
                if (ballIsPresent && !ballWasPresent) {
                    // Rising edge - ball just entered exit sensor range
                    // Don't count yet, wait for it to fully exit
                } else if (!ballIsPresent && ballWasPresent) {
                    // Falling edge - ball just left exit sensor range
                    // This means a ball exited completely
                    currentCount++;
                }
                
                ballWasPresent = ballIsPresent;
                lastStateChangeTime = pros::millis();
            }
        }
        
        // Allow intake motors to run
        pros::delay(SAMPLE_DELAY);
    }
    
    isDone = true;
    return true;  // Successfully counted all balls exiting
}

bool noBallsLeft() {
    // Note: Optical sensor uses proximity - higher values mean closer
    const int BALL_THRESHOLD = 80;  // Adjust based on testing

    while (topOptical.get_proximity() > BALL_THRESHOLD) {
        pros::delay(200);
        while (topOptical.get_proximity() < BALL_THRESHOLD) {
            pros::delay(100);
        }
    }
    return true;
   
}
bool empty() {
    // Note: Optical sensor uses proximity - higher values mean closer
    const int EMPTY_THRESHOLD = 40;  // Adjust based on testing
    return topOptical.get_proximity() < EMPTY_THRESHOLD;
}
void load() {
    hoard.set_value(true);
    intakeBottom.move(127);
    intakeTop.move(-40);
    intakeOn = true;
}
void slowExtake() {
    intakeBottom.move(0);
    intakeTop.move(127);
    intakeOn = true;
}
void unload() {
    hoard.set_value(false);
    intakeBottom.move(127);
    intakeTop.move(-127);
    intakeOn = true;  // Intake is running during unload
}
void middleGetBall() {
    intakeBottom.move(-127);
    intakeTop.move(-127);
}
void slowUnload() {
    hoard.set_value(false);
    intakeBottom.move(127);
    intakeTop.move(-80);
    intakeOn = true;  // Intake is running during unload
}
void middleScore() {
    hoard.set_value(false);
    intakeBottom.move(127);
    intakeTop.move(127);
    intakeOn = true;  // Intake is running during scoring
}
void slowMiddleScore() {
    intakeBottom.move(110);
    intakeTop.move(70);
    intakeOn = true;  // Intake is running during scoring
}
void rest() {
    intakeBottom.move(0);
    intakeTop.move(0);
    intakeOn = false;  // Intake is stopped
}
void extake() {
    intakeBottom.move(-127);
    intakeTop.move(127);
    intakeOn = true;
}

// Autonomous helper function - blocks until balls are loaded or timeout
bool loadBallsAuto(int ballCount, int timeoutMs) {
    // Start the intake
    load();
    
    // Wait for balls (this function blocks internally)
    bool success = firstStageCounted(ballCount, timeoutMs);
    
    // Stop the intake
    rest();
    
    // Return whether we successfully loaded all balls
    return success;
}

// Non-blocking version that can run concurrently with chassis movement
pros::Task* loadBallsAsync(int ballCount, int timeoutMs) {
    return new pros::Task([ballCount, timeoutMs] {
        loadBallsAuto(ballCount, timeoutMs);
    });
}

// Autonomous helper function for scoring - blocks until balls are scored or timeout
bool scoreBallsAuto(int ballCount, int timeoutMs) {
    // Start the scoring motors (high goal)
    unload();
    
    // Wait for balls to exit (this function blocks internally)
    bool success = secondStageCounted(ballCount, timeoutMs);
    
    // Stop the motors
    rest();
    
    // Return whether we successfully scored all balls
    return success;
}

// Non-blocking version for scoring
pros::Task* scoreBallsAsync(int ballCount, int timeoutMs) {
    return new pros::Task([ballCount, timeoutMs] {
        scoreBallsAuto(ballCount, timeoutMs);
    });
}

// Middle goal scoring - blocks until balls are scored or timeout
bool middleScoreAuto(int ballCount, int timeoutMs) {
    // Start the middle scoring motors
    middleScore();
    
    // Wait for balls to exit (this function blocks internally)
    bool success = secondStageCounted(ballCount, timeoutMs);
    
    // Stop the motors
    rest();
    
    // Return whether we successfully scored all balls
    return success;
}

// Non-blocking version for middle scoring
pros::Task* middleScoreAsync(int ballCount, int timeoutMs) {
    return new pros::Task([ballCount, timeoutMs] {
        middleScoreAuto(ballCount, timeoutMs);
    });
}

void unjam() {
    if(intakeBottom.get_target_velocity() - intakeBottom.get_actual_velocity() > 300.0 ) {
        pros::delay(1000);
        if(intakeBottom.get_target_velocity() - intakeBottom.get_actual_velocity() > 300.0) {
        extake();
        pros::delay(300);
        rest();
        pros::delay(1000);
        }
    }
}
// Control functions for unjam feature
void enableUnjam() {
    unjamEnabled = true;
}

void disableUnjam() {
    unjamEnabled = false;
}

bool isUnjamEnabled() {
    return unjamEnabled;
}

// Index/score control function - runs intake until specified number of balls scored
void stopUntilScored(int ballsToScore) {
    // Start scoring - intake motors run to eject balls
    unload();
    
    int scoredCount = 0;
    
    // Threshold values for optical sensor
    // Note: Optical sensor uses proximity - higher values mean closer/ball present
    const int BALL_PRESENT_THRESHOLD = 80;  // Higher threshold for better ball detection
    const int BALL_ABSENT_THRESHOLD = 40;   // Lower threshold to confirm ball has left
    const int DEBOUNCE_MS = 30;  // Debounce time for stable reading
    const int MIN_BALL_GAP_MS = 50;  // Minimum time between ball counts (prevents double-counting)
    const int SAMPLE_DELAY = 5;  // Delay between sensor samples
    
    // State tracking for edge detection
    bool ballWasPresent = false;
    int lastBallCountTime = 0;  // Track when we last counted a ball
    
    while (scoredCount < ballsToScore) {
        // Get current sensor reading
        int currentReading = topOptical.get_proximity();
        
        // Use hysteresis: different thresholds for detecting vs losing ball
        bool ballIsPresent;
        if (ballWasPresent) {
            // Ball was present, use lower threshold to detect when it leaves
            ballIsPresent = currentReading > BALL_ABSENT_THRESHOLD;
        } else {
            // No ball detected, use higher threshold to detect new ball
            ballIsPresent = currentReading > BALL_PRESENT_THRESHOLD;
        }
        
        // Debounce check - ensure stable reading for DEBOUNCE_MS
        if (ballIsPresent != ballWasPresent) {
            // State might be changing, wait for stable reading
            int stableReadingStart = pros::millis();
            bool isStable = true;
            
            while (pros::millis() - stableReadingStart < DEBOUNCE_MS) {
                int newReading = topOptical.get_proximity();
                bool newBallPresent;
                
                // Apply same hysteresis logic during debounce
                if (ballWasPresent) {
                    newBallPresent = newReading > BALL_ABSENT_THRESHOLD;
                } else {
                    newBallPresent = newReading > BALL_PRESENT_THRESHOLD;
                }
                
                if (newBallPresent != ballIsPresent) {
                    // Reading changed during debounce period, restart
                    isStable = false;
                    break;
                }
                
                pros::delay(SAMPLE_DELAY);
            }
            
            if (isStable) {
                // Stable state change detected
                int currentTime = pros::millis();
                
                if (!ballIsPresent && ballWasPresent) {
                    // Falling edge - ball just left sensor range
                    // Only count if enough time has passed since last ball (prevents double-counting)
                    if (currentTime - lastBallCountTime >= MIN_BALL_GAP_MS) {
                        scoredCount++;
                        lastBallCountTime = currentTime;
                    }
                }
                
                ballWasPresent = ballIsPresent;
            }
        }
        
        // Small delay between checks
        pros::delay(SAMPLE_DELAY);
    }
    
    // All balls scored, stop the intake
    extake();
    pros::delay(300);
    rest();
    
    
}

// Color detection function - stops intake when RED ball is detected
void stopWhenRed() {
    const int DETECT_PROXIMITY = 100;  // Proximity threshold to ensure ball is present
    const int DEBOUNCE_MS = 50;  // Debounce time for stable color reading
    const int SAMPLE_DELAY = 10;  // Delay between sensor samples
    
    while (true) {
        // Check if a ball is close enough to read color
        int proximity = topOptical.get_proximity();
        
        if (proximity > DETECT_PROXIMITY) {
            // Ball is present, check its color
            double hue = topOptical.get_hue();
            bool blockIsRed = hue > 340 || hue < 100;
            
            if (blockIsRed) {
                // Red ball detected, verify with debounce
                int stableReadingStart = pros::millis();
                bool isStableRed = true;
                
                while (pros::millis() - stableReadingStart < DEBOUNCE_MS) {
                    double newHue = topOptical.get_hue();
                    int newProximity = topOptical.get_proximity();
                    bool stillRed = newHue > 340 || newHue < 100;
                    
                    if (!stillRed || newProximity < DETECT_PROXIMITY) {
                        // Color changed or ball moved away during debounce
                        isStableRed = false;
                        break;
                    }
                    
                    pros::delay(5);
                }
                
                if (isStableRed) {
                    // Confirmed red ball, stop the intake
                    rest();
                    return;
                }
            }
        }
        
        // Continue checking
        pros::delay(SAMPLE_DELAY);
    }
}

// Color detection function - stops intake when BLUE ball is detected
// Returns a task that runs asynchronously, allowing chassis to move while monitoring
pros::Task* stopWhenBlue() {
    return new pros::Task([]() {
        const int DETECT_PROXIMITY = 100;  // Proximity threshold to ensure ball is present
        const int DEBOUNCE_MS = 50;  // Debounce time for stable color reading
        const int SAMPLE_DELAY = 10;  // Delay between sensor samples
        
        while (true) {
            // Check if a ball is close enough to read color
            int proximity = topOptical.get_proximity();
            
            if (proximity > DETECT_PROXIMITY) {
                // Ball is present, check its color
                double hue = topOptical.get_hue();
                bool blockIsBlue = hue > 150 && hue < 290;
                
                if (blockIsBlue) {
                    // Blue ball detected, verify with debounce
                    int stableReadingStart = pros::millis();
                    bool isStableBlue = true;
                    
                    while (pros::millis() - stableReadingStart < DEBOUNCE_MS) {
                        double newHue = topOptical.get_hue();
                        int newProximity = topOptical.get_proximity();
                        bool stillBlue = newHue > 150 && newHue < 290;
                        
                        if (!stillBlue || newProximity < DETECT_PROXIMITY) {
                            // Color changed or ball moved away during debounce
                            isStableBlue = false;
                            break;
                        }
                        
                        pros::delay(5);
                    }
                    
                    if (isStableBlue) {
                        // Confirmed blue ball, stop the intake
                        rest();
                        return;  // Task completes after stopping intake
                    }
                }
            }
            
            // Continue checking
            pros::delay(SAMPLE_DELAY);
        }
    });
}