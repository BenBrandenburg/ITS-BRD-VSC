#ifndef ERRORHANDLING_h
#define ERRORHANDLING_h
//
#define SUCCESS 0
#define STACK_EMPTY -1
#define STACK_OVERFLOW -2
#define STACK_UNDERFLOW -3
#define INTEGER_OVERFLOW -4
#define INTEGER_UNDERFLOW -5
#define ZERO_DIVISION -6
#define UNEXPECTED_INPUT -7
#define STACK_COUNT_1 -8
#define ENTER_NOT_PRESSED -9

#define STACK_EMPTY_MSG "Stack is empty!"
#define STACK_OVERFLOW_MSG "Stackoverflow!"
#define STACK_UNDERFLOW_MSG "Stackunderflow!"
#define INTEGER_OVERFLOW_MSG "Integeroverflow!"
#define INTEGER_UNDERFLOW_MSG "Integerunderflow!"
#define ZERO_DIVISION_MSG "Zero devision!"
#define UNEXPECTED_INPUT_MSG "Unexpecet input!"
#define STACK_COUNT_1_MSG "Stack count is 1 or \nless!"
#define ENTER_NOT_PRESSED_MSG "Only press empty button to enter number!"


/*
***********************************************************************
@brief : Check if error happened and resolve it

@param : Errorcode as int
***********************************************************************
*/
void handleError (int errorCode);

/*
***********************************************************************
@brief : Set error state 

@param : Error message
***********************************************************************
*/
void setErrorState (char* errMsg);

#endif
// EOF