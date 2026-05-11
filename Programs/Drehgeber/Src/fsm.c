#include "fsm.h"
#include "display.h"
#include "fsmStates.h"
#include "gpio.h"
#include "computing.h"
#include "time.h"
#include <stdbool.h>
#include <stdint.h>

#define MIN_TIME 0.25
#define MAX_TIME 0.5

void getInput();
void changeState();
void processInput();
void outPut();

void setErrorState();
void reset();
void countSteps();
void changePhaseDiff();


static FsmState phaseToState[4][4] = {
    {Idle, Reverse, Forward, Error},
    {Forward, Idle, Error, Reverse},
    {Reverse, Error, Idle, Forward},
    {Error, Forward, Reverse, Idle}
};

static FsmState state_ = Idle;
static int counter_ = 0; // nur für gpio output, kann negativ sein
static int lastCounter_ = 0;

static int phaseDiffCounter_ = 0;

static Phase currentPhase_;
static Phase previousPhase_;
static bool s6Pressed_ = false;

static double angle_ = 0.0;
static double velocity_ = 0.0;
static uint32_t currentTime_ = 0;
static uint32_t lastTime_;

void fsm_run() {
    startDisplay();
    initTime();
    reset();

    while(1) {
        getInput(); 
        changeState();
        if (state_ == Error && (s6Pressed_)) reset();
        processInput();
        outPut();
    }
}

/*
holt die neuesten daten und speichert sie ab
*/
void getInput() {
    currentPhase_ = gpioInput_getPhase();
    currentTime_ = getTime();
    s6Pressed_ = gpioInput_S6Pressed();
}

void changeState() {
    if (state_ == Error) return;
    state_ = phaseToState[previousPhase_][currentPhase_];
}

void processInput() {
    if (state_ == Error) return;

    countSteps();
    
    double dt = getDt(currentTime_, lastTime_);
    if ((dt >= MIN_TIME && currentPhase_ != previousPhase_) || (dt >= MAX_TIME)) {
        changePhaseDiff();  
        angle_ = computing_getRotationAngle(counter_);
        velocity_ = computing_getAngleVelocity(phaseDiffCounter_, dt);
        update_displayBuffer(angle_, velocity_);
        lastTime_ = currentTime_;
    }
    previousPhase_ = currentPhase_;
}

void outPut() {
    ledD20_high();
    update_display();
    update_gpioOutput(counter_, state_);
    ledD20_low();
}

void reset() {
    currentPhase_ = gpioInput_getPhase();
    previousPhase_ = currentPhase_;
    lastTime_ = getTime();
    counter_ = 0;
    lastCounter_ = 0;
    currentTime_ = 0;
    phaseDiffCounter_ = 0;
    state_ = Idle;
}
/* 
*/
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
berechnet die differrenz zwischen dem alten phasencounterr mit dem neuem phasencounter
*/
void changePhaseDiff (){
    phaseDiffCounter_ = counter_ - lastCounter_;
    lastCounter_ = counter_; 
}
// EOF