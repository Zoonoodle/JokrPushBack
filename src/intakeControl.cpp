#include "intakeControl.h"
#include "robotConfigs.h"
void doublePark() {
    while(bottomDist.get() > 200) {
        intakeBottom.move(-127);
    }
    while(bottomDist.get() < 220){
        intakeBottom.move(-80);
    }
    intakeBottom.move(0);
    park.set_value(true);
}
void load() {
    intakeBottom.move(127);
    intakeTop.move(-127);
}
void unload() {
    intakeBottom.move(-127);
    intakeTop.move(127);
}
void middleScore() {
    intakeBottom.move(127);
    intakeTop.move(100);
}