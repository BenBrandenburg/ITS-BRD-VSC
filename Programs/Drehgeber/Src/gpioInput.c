#include "gpioInput.h"
#include "stm32f4xx.h"


Phase gpioInput_getPhase(void) {
    return(GPIOF->IDR & 0x3U); // mit 3 verunden, damit nur erste beide bit "angeschaut werden"
}

bool gpioInput_S6Pressed(void) {
    return !(GPIOF->IDR & (1 << 6)); // s6 ist 6tes bit von gpiof
}