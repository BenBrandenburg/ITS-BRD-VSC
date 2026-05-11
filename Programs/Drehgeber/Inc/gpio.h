#ifndef GPIOINTPUT_H
#define GPIOINTPUT_H

#include <stdbool.h>
#include "fsmStates.h"
#include <stdint.h>

typedef enum {
    PHASE_A = 0, // 00 
    PHASE_D = 1, // 01 
    PHASE_B = 2, // 10 
    PHASE_C = 3  // 11
} Phase;


// returns the encoder input as a Phase
Phase gpioInput_getPhase(void);

// checks if reset button is pressed
bool gpioInput_S6Pressed(void);

// updates all output leds depending on state of fsm
void update_gpioOutput(uint8_t counter, FsmState state);

void ledD20_high();

void ledD20_low();

#endif
// EOF