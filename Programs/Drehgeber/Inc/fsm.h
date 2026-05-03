#ifndef FSM_H
#define FSM_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648


typedef enum{
    Reverse, Forward, Idle, Error 
} State;

void run();


static void changeState();
static void setErrorState();
static void reset();
static void countSteps();
static int changePhaseDiff();


#endif 
// EOF