#include "errorHandling.h"
#include "scanner.h"
#include "display.h"
#include "stack.h"

#define STACK_EMPTY_MSG "Stack is empty!"
#define STACK_OVERFLOW_MSG "Stackoverflow!"
#define STACK_UNDERFLOW_MSG "Stackunderflow!"
#define INTEGER_OVERFLOW_MSG "Integeroverflow!"
#define INTEGER_UNDERFLOW_MSG "Integerunderflow!"
#define ZERO_DIVISION_MSG "Zero devision!"
#define UNEXPECTED_INPUT_MSG "Unexpecet input!"
#define STACK_COUNT_1_MSG "Stack count is 1 or \nless!"

void handleError (int errorCode) {
    switch (errorCode) {
        case SUCCESS: return;
        case STACK_EMPTY: 
            setErrorState(STACK_EMPTY_MSG);
            break;
        case STACK_OVERFLOW: 
            setErrorState(STACK_OVERFLOW_MSG);
            break;
        case STACK_UNDERFLOW: 
            setErrorState(STACK_UNDERFLOW_MSG);
            break;
        case INTEGER_OVERFLOW: 
            setErrorState(INTEGER_OVERFLOW_MSG);
            break;
        case INTEGER_UNDERFLOW: 
            setErrorState(INTEGER_UNDERFLOW_MSG);
            break;
        case ZERO_DIVISION: 
            setErrorState(ZERO_DIVISION_MSG);
            break;
        case UNEXPECTED_INPUT:
            setErrorState(UNEXPECTED_INPUT_MSG);
            break;
        case STACK_COUNT_1:
            setErrorState(STACK_COUNT_1_MSG);
            break;
        default: break;
    }
    return;
}

void setErrorState (char* errMsg) {
    char stackResetMsg[] = "Stack resetted!\n";
    setErrMode();
    printStdout(errMsg);
    printStdout("\nPress \"C\" to restart!\n");
    while (nextToken().tok != CLEAR) {
    }
    setNormalMode();
    stack_reset();
    printStdout(stackResetMsg);
}