// Example usage patterns for ball loading in autonomous
#include "intakeControl.h"
#include "robotConfigs.h"

// EXAMPLE 1: Simple blocking load at matchload zone
void matchloadSequence() {
    // Drive to matchload position
    chassis.moveTo(10, 20, 3000);
    
    // Load 3 balls (blocks until done or timeout)
    if (loadBallsAuto(3, 8000)) {
        // Success - got all 3 balls, continue route
        chassis.moveTo(50, 50, 3000);
    } else {
        // Timeout - didn't get all balls, but continue anyway
        chassis.moveTo(50, 50, 3000);
    }
}

// EXAMPLE 2: Start loading while driving away (non-blocking)
void efficientMatchload() {
    // Start at matchload position
    
    // Begin loading balls asynchronously
    pros::Task* loadTask = loadBallsAsync(3, 8000);
    
    // Drive away while still loading
    chassis.moveTo(30, 30, 2000);
    
    // Wait for loading to complete before next action
    loadTask->join();  // Blocks until loading is done
    delete loadTask;
    
    // Now ready to score or continue
    chassis.moveTo(60, 60, 3000);
}

// EXAMPLE 3: Manual control for complex sequences
void complexLoadSequence() {
    // Drive to position
    chassis.moveTo(10, 20, 3000);
    
    // Start intake
    load();
    
    // Wait for first 2 balls
    if (firstStageCounted(2, 5000)) {
        // Got 2 balls, drive forward slightly
        chassis.moveRelative(5, 0, 1000);
        
        // Wait for 3rd ball
        if (firstStageCounted(1, 3000)) {
            // Success
        }
    }
    
    // Stop intake
    rest();
    
    // Continue autonomous
    chassis.moveTo(50, 50, 3000);
}

// EXAMPLE 4: Loading with error recovery
void robustLoadSequence() {
    int attempts = 0;
    bool loaded = false;
    
    // Try loading up to 2 times
    while (!loaded && attempts < 2) {
        chassis.moveTo(10, 20, 3000);  // Approach matchload
        
        loaded = loadBallsAuto(3, 5000);
        
        if (!loaded) {
            // Back up and try again
            chassis.moveRelative(-10, 0, 1000);
            attempts++;
        }
    }
    
    // Continue regardless
    chassis.moveTo(50, 50, 3000);
}

// ============ SCORING EXAMPLES ============

// EXAMPLE 5: Simple blocking score
void simpleScoreSequence() {
    // Drive to goal
    chassis.moveTo(60, 60, 3000);
    
    // Score 3 balls into high goal (blocks until done or timeout)
    if (scoreBallsAuto(3, 5000)) {
        // Success - all balls scored
        chassis.moveRelative(-20, 0, 2000);  // Back away
    } else {
        // Timeout - not all balls scored
        rest();  // Ensure motors stopped
        chassis.moveRelative(-20, 0, 2000);  // Back away anyway
    }
}

// EXAMPLE 6: Middle goal scoring
void middleGoalSequence() {
    // Drive to middle goal position
    chassis.moveTo(40, 40, 3000);
    
    // Score into middle goal
    middleScoreAuto(2, 4000);
    
    // Continue route
    chassis.moveTo(70, 70, 3000);
}

// EXAMPLE 7: Efficient scoring while repositioning
void efficientScoreSequence() {
    // Drive to goal
    chassis.moveTo(60, 60, 3000);
    
    // Start scoring asynchronously
    pros::Task* scoreTask = scoreBallsAsync(3, 5000);
    
    // Begin backing away while still scoring
    pros::delay(1000);  // Let scoring start
    chassis.moveRelative(-10, 0, 2000);
    
    // Wait for scoring to complete
    scoreTask->join();
    delete scoreTask;
    
    // Continue route
    chassis.moveTo(30, 30, 3000);
}

// EXAMPLE 8: Full autonomous flow - load then score
void fullAutoSequence() {
    // Start at matchload
    
    // Load 3 balls
    if (!loadBallsAuto(3, 8000)) {
        // Timeout loading - continue with whatever we got
    }
    
    // Drive to goal
    chassis.moveTo(60, 60, 4000);
    
    // Score all balls we have
    scoreBallsAuto(3, 5000);
    
    // Return to matchload
    chassis.moveTo(10, 20, 4000, {.forwards = false});
    
    // Load again
    loadBallsAuto(3, 8000);
    
    // Score at middle goal this time
    chassis.moveTo(40, 40, 3000);
    middleScoreAuto(3, 5000);
}