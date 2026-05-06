#include "gpioInput.h"
#include "stm32f4xx.h"

#define LED_FORWARD 7 
#define LED_REVERSE 6
#define LED_ERROR 5

static FsmState lastState_;

Phase gpioInput_getPhase(void) {
    return(GPIOF->IDR & 0x3U); // mit 3 verunden, damit nur erste beide bit "angeschaut werden"
}

bool gpioInput_S6Pressed(void) {
    return !(GPIOF->IDR & (1 << 6)); // s6 ist 6tes bit von gpiof
}

void gpioOutput_update(uint8_t counter, FsmState state) {
    if (state == Idle) return;
    if (lastState_ != state) {
        GPIOE->BSRR = (0xff << 16); // resette alle state leds
    
        switch (state) {
            case Forward:
                GPIOE->BSRR = (1 << LED_FORWARD);
                break;
            case Reverse:
                GPIOE->BSRR = (1 << LED_REVERSE);
                break;
            case Error:
                GPIOE->BSSR = (1 << 13); // 14tes bit togglen
                break;
            default:
        }
    }

    // counter leds aktualisieren
    GPIOD->BSRR = (0xff << 16); // resette alle counter leds

    GPIOD->BSRR = counter; // counter leds an schalten

    lastState_ = state;
}