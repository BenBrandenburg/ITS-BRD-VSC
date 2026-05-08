#ifndef TIME_H
#define TIME_H

#include <stdint.h>

void initTime();
uint32_t getTime();
double getDt(uint32_t t2, uint32_t t1);

#endif
// EOF