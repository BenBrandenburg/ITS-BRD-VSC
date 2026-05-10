#ifndef TIME_H
#define TIME_H

#define TICKS_PER_SEC 90000000 // der Timer tickt  90-Millionen mal pro Sekunde

#include <stdint.h>

// init the timer register
void initTime();

// get a timestamp
uint32_t getTime();

//  return the delta between 2 timestamps
double getDt(uint32_t t2, uint32_t t1);

#endif
// EOF