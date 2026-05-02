#ifndef FSM_H
#define FSM_H


typedef enum{
    Reverse, Forward, Idle, Error 
} State;

void changeState(Phase currentPhase);



#endif 
// EOF