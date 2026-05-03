#ifndef GPIOINTPUT_H
#define GPIOINTPUT_H

#include <stdbool>

typedef enum {
    PHASE_A = 0, // 00 
    PHASE_D = 1, // 01 
    PHASE_B = 2, // 10 
    PHASE_C = 3  // 11
} Phase;

Phase gpioInput_getPhase(void);

bool gpioInput_S6Pressed(void);

#endif
// EOF