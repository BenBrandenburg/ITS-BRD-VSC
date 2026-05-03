#include "fsm.h"
#include <stdbool>

static State phaseToState[4][4] = {
    {Idle, Reverse, Forward, Error},
    {Forward, Idle, Error, Reverse},
    {Reverse, Error, Idle, Forward},
    {Error, Forward, Reverse, Idle}
};

static State state_ = Idle;
static int counter_ = 0;
static Phase currentPhase_ = PHASE_A;
static Phase previousPhase_ = PHASE_A;
static uint32_t currentTime_ = 0;
static uint32_t lastTime_ = 0;

void run() {
    while(1) {
        currentPhase_ = gpioInput_getPhase();
        currentTime_ = getTimeStamp();

        changeState();
        countSteps();

        // winkelberechnung + geschwindigkeit

        if (state_ == Forward) // gpioOutput forward
        if (state_ == Reverse) // gpioOutput reverse

        previousPhase_ = currentPhase_;
        lastTime_ = currentTime_;
    }
}

void changeState() {
    state_ = phaseToState[previousPhase_][currentPhase_];
    if (state_ == Error) setErrorState();
}

void setErrorState() {
    while (!gpioInput_S6Pressed()) {
        // Print error out
    }
    reset();
}

void reset() {
    isError_ = false;
    counter_ = 0;
    currentTime_ = 0;
    lastTime_ = 0;
}

void countSteps() {
    if (state_ == Forward) {
        if (counter_ == INT_MAX) {
            counter_ = INT_MIN;
        }
        else {
            counter_++;
        }
    }
    if (state_ == Reverse) {
        if (counter_ == INT_MIN) {
            counter_ = INT_MAX;
        }
        else {
            counter_--;            
        }
    }
}
// EOF