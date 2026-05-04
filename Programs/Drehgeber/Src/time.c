#include "time.h"
#include "timer.h" 

#define TICKS_PER_SEC 90000000 // der Timer tickt  90-Millionen mal pro Sekunde

void initTime() {
    initTimer();
}

uint32_t getTime() {
    return getTimeStamp();
}

double getDt(uint32_t t2, uint32_t t1) {
    double dt = (double) ((t2-t1) * TICKS_PER_SEC);
    return dt < 0.0 ? dt * (-1.0) : dt;
}