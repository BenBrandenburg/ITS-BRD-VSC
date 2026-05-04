#ifndef FSM_H
#define FSM_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void run();

static void getInput();
static void changeState();
static void processInput();
static void outPut();

static void setErrorState();
static void reset();
static void countSteps();
static int changePhaseDiff();

#endif 
// EOF