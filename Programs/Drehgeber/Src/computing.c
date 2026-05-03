#include "fsm.h"

// berechnet den winkel 
double computing_getRotationAngle(int counter){
    double angle = counter * 0.3;
    return angle;
}

// berechnet die geschbwindigkeit
double computing_getAngleVelocity(int diffBetweenPhases, uint32_t Dt ){
    double velocity = ( diffBetweenPhases * 0.3 ) / Dt;
    return velocity;
    
}


