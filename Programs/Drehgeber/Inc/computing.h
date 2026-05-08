#ifndef COMPUTING_H
#define COMPUTING_H
#include <stdint.h>

#define SLOTS 300


double computing_getRotationAngle(int counter);
double computing_getAngleVelocity(int diffBetweenPhases, uint32_t dt);


#endif 
// EOF