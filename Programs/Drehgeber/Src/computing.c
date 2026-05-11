#include <stdint.h>

//#define SIGNAL_PRO360 360/1200

// berechnet den winkel 
double computing_getRotationAngle(int counter){
    double angle = counter * 0.3;
    return angle;
}

// berechnet die winkel geschwindigkeit
double computing_getAngleVelocity(int diffBetweenPhases, double dt){ 
    double velocity = (diffBetweenPhases * 0.3 ) / dt;
    return velocity;
}
// EOF