#include "errorHandling.h"
#include "scanner.h"
#include "display.h"
#include "stack.h"

void handleError (int* errorCode) {
    switch (errorCode) {
        case SUCCESS: return;
        case STACK_EMPTY: 
            setErrorState (STACK_EMPTY_MSG);
            break;
        case STACK_OVERFLOW: 
            setErrorState (STACK_OVERFLOW_MSG);
            break;
        case STACK_UNDERFLOW: 
            setErrorState (STACK_UNDERFLOW_MSG);
            break;
        case INTEGER_OVERFLOW: 
            setErrorState (INTEGER_OVERFLOW_MSG);
            break;
        case INTEGER_UNDERFLOW: 
            setErrorState (INTEGER_UNDERFLOW_MSG);
            break;
        case ZERO_DIVISION: 
            setErrorState (ZERO_DIVISION_MSG);
            break;
        default: break;
    }
    return;
}

void setErrorState (char* errMsg) {
    setErrMode();
    printStdOut(errMsg);
    printStdOut("Press \"C\" to restart!\n");
    While (nextToken().tok != CLEAR) {
    }
    setNormalMode();
    stack_reset();
}