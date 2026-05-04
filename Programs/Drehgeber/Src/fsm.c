#include "fsm.h"
#include "display.h"
#include "fsmStates.h"
#include <stdbool>

static FsmState phaseToState[4][4] = {
    {Idle, Reverse, Forward, Error},
    {Forward, Idle, Error, Reverse},
    {Reverse, Error, Idle, Forward},
    {Error, Forward, Reverse, Idle}
};

static FsmState state_ = Idle;
static int counter_ = 0;
static int phaseCounter_ = 0;
static int lastPhaseCounter_ = 0;
static int phaseDiffCounter_ = 0;
static Phase currentPhase_ = PHASE_A;
static Phase previousPhase_ = PHASE_A;
static uint32_t currentTime_ = 0;
static uint32_t lastTime_ = 0;

void run() {
    while(1) {
        getInput(); 
        changeState();
        processInput();
        outPut();
    } 
}

void getInput() {
    currentPhase_ = gpioInput_getPhase();
    currentTime_ = getTimeStamp();
}

void changeState() {
    state_ = phaseToState[previousPhase_][currentPhase_];
}

void processInput() {
     if (state_ == Error) setErrorState();

     if (state_ == Forward || state_  == Reverse) ++phaseCounter_; 

        countSteps();
        
    if (0.25 <= getDt(currentTime_, lastTime_)){
        changePhaseDiff();  
        double angle = computing_getRotationAngle(counter_);
        double velocity = computing_getAngleVelocity(phaseDiffCounter,currentTime_ - lastTime_);
        update_display(angle,velocity);
        lastTime_ = currentTime_;
    }

        if (state_ == Forward) // gpioOutput forward
        if (state_ == Reverse) // gpioOutput reverse

        previousPhase_ = currentPhase_;
}

void outPut() {
    update_display(angle, velocity);
    update_gpioOutput(counter_, )
}


void setErrorState() {
    while (!gpioInput_S6Pressed()) {
        // Print error out
    }
    reset();
}

void reset() {
    counter_ = 0;
    currentTime_ = 0;
    lastTime_ = 0;
    phaseCounter_ = 0;
    lastPhaseCounter_ = 0;
    phaseDiffCounter_ = 0;
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

/* 
berechnet die diefferrenz zwischen dem alten phasencounterr mit dem neuem phasencounter*/
void changePhaseDiff (){
    phaseDiffCounter_ = phaseCounter_ - lastPhaseCounter_;
    lastPhaseCounter_ = phaseCounter_; 
}

// EOF