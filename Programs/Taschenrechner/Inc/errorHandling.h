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