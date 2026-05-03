#include "time.h"
#include "timer.h" 

#define TICKS_PER_SEK 90000000 // der Timer tickt  90-Millionen mal pro Sekunde

void initTime() {
    initTimer();
}

uint32_t getTime() {
    return getTimeStamp();
}

double getDt(uint32_t t2, uint32_t t1) {
    return (double) ((t2-t1) * TICKS_PER_SEK);
}