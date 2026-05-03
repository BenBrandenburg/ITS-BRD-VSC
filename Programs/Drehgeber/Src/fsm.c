#include "fsm.h"

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
static int s6Pressed_ = 0;

void run() {
    while(1) {
        currentPhase_ = gpioInput_getPhase();

        s6Pressed_ = gpioInput_S6Pressed();

        changeState();
        countSteps();

        previousPhase_ = currentPhase_;
    }
}

void changeState() {
    state_ = phaseToState[previousPhase_][currentPhase_];
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