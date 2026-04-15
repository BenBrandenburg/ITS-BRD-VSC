#ifndef STACK_h
#define STACK_h
#define INT_MAX 2147483647
#define INT_MIN -2147483648

/*
@brief : Clear all values from stack 

@return : -1 if stack empty
*/
int stack_reset();

/*
***********************************************************************
@brief : Push an integer value on stack

@param : pushed int

@return errorCode
***********************************************************************
*/
int stack_push(int val);

/*
***********************************************************************
@brief : Pop an integer value of stack

@param : popped int pointer

@return errorCode
***********************************************************************
*/
int stack_pop(int *ptr);

/*
***********************************************************************
@brief : Look at the top val of stack

@param : pointer to peeked int

@return errorCode
***********************************************************************
*/
int stack_peek(int *ptr);

/*
***********************************************************************
@brief : Returns number of stack items

@return errorCode
***********************************************************************
*/
int stack_getCount();

/*
***********************************************************************
@brief : puts address of top element in param

@param : pointer

@return errorCode
***********************************************************************
*/
int stack_topElemPtr(int **ptr);

#endif
// EOF