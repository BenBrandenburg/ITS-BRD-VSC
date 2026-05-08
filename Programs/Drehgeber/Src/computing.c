#include <stdint.h>
// berechnet den winkel 
double computing_getRotationAngle(int counter){
    double angle = counter * 0.3;
    return angle;
}

// berechnet die winkel geschwindigkeit
double computing_getAngleVelocity(int diffBetweenPhases, uint32_t dt){
    double t_in_sec = (double) dt / 90000000; 
    double velocity = (diffBetweenPhases * 0.3 ) / t_in_sec;
    return velocity;
    
}


