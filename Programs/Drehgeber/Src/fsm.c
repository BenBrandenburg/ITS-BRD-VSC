#include "fsm.h"
#include "display.h"
#include "fsmStates.h"
#include "gpioInput.h"
#include "gpioOutput.h"
#include "computing.h"
#include "time.h"
#include <stdbool.h>
#include <stdint.h>

static FsmState phaseToState[4][4] = {
    {Idle, Reverse, Forward, Error},
    {Forward, Idle, Error, Reverse},
    {Reverse, Error, Idle, Forward},
    {Error, Forward, Reverse, Idle}
};

static FsmState state_ = Idle;
static int counter_ = 0; // nur für gpio output, kann negativ sein

static int phaseCounter_ = 0;   // für berechnungen
static int lastPhaseCounter_ = 0;
static int phaseDiffCounter_ = 0;

static Phase currentPhase_ = PHASE_A;
static Phase previousPhase_ = PHASE_A;

static double angle_ = 0.0;
static double velocity_ = 0.0;
static uint32_t currentTime_ = 0;
static uint32_t lastTime_ = 0;

void fsm_run() {
    while(1) {
        getInput(); 
        changeState();
        processInput();
        outPut();
    }
}

void getInput() {
    currentPhase_ = gpioInput_getPhase();
    currentTime_ = getTime();
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
        angle_ = computing_getRotationAngle(counter_);
        velocity_ = computing_getAngleVelocity(phaseDiffCounter_, (currentTime_ - lastTime_ ));
        update_display(angle,velocity);
        lastTime_ = currentTime_;
    }
        previousPhase_ = currentPhase_;
}

void outPut() {
    update_display(angle_, velocity_);
    update_gpioOutput(counter_, state_);
}


void setErrorState() {
    gpioOutput_toggleErrorLed(); // error led an
    while (!gpioInput_S6Pressed()) {
    }
    void gpioOutput_toggleErrorLed(); // error led aus
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


// berechnet die differrenz zwischen dem alten phasencounterr mit dem neuem phasencounter
void changePhaseDiff (){
    phaseDiffCounter_ = phaseCounter_ - lastPhaseCounter_;
    lastPhaseCounter_ = phaseCounter_; 
}

// EOF