#ifndef STACK.h
#define STACK.h

/*
@brief : Clear all values from stack 

@return : -1 if stack empty
*/
int stack_reset();

/*
***********************************************************************
@brief : Push an integer value on stack

@param : int pointer for failure (-1)

@return pushed int
***********************************************************************
*/
int stack_push(int);

/*
***********************************************************************
@brief : Pop an integer value of stack

@param : Int pointer for failure (-1 if stack empty)

@return Integer from stack
***********************************************************************
*/
int stack_pop(int*);

/*
***********************************************************************
@brief : Look at the top val of stack

@param : Int pointer for failure (-1 if stack empty)

@return value of top of stack
***********************************************************************
*/
int stack_peek(int*);

/*
***********************************************************************
@brief : Returns number of stack items

@return number of stack items
***********************************************************************
*/
int getCount();

#endif
// EOF