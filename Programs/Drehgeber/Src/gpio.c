#include "gpioInput.h"
#include "stm32f4xx.h"


Phase gpioInput_getPhase(void) {
    return(GPIOF->IDR & 0x3U); // mit 3 verunden, damit nur erste beide bit "angeschaut werden"
}

bool gpioInput_S6Pressed(void) {
    return !(GPIOF->IDR & (1 << 6)); // s6 ist 6tes bit von gpiof
}

void gpioOutput_update(int counter, FsmState state) {
    GPIOD->BSRR = 0; // resette alle leds

    (GPIOD->BSRR & (counter & 63)); // den counter mit 63 verunden, damit nur die ersten 6 bit beachtet werden

    if (state == Forward) {
        GPIOD->BSRR & (1 << 15); // 16tes bit anschalten 
    }

    if (state == Reverse) {
        GPIOD->BSRR & (1 << 14); // 15tes bit anschalten
    }
}

void gpioOutput_toggleErrorLed() {
    GPIOD->BSSR ^ (1 << 13); // 14tes bit togglen
}