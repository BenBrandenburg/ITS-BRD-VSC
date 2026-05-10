#include "time.h"
#include "timer.h" 

void initTime() {
    initTimer();
}

uint32_t getTime() {
    return getTimeStamp();
}

double getDt(uint32_t t2, uint32_t t1) {
    uint32_t diff = t2 - t1;
    return (double) diff / TICKS_PER_SEC;
}
// EOF