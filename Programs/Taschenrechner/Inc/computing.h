#ifndef COMPUTING_h
#define COMPUTING_h

/*
 ****************************************************************************************
 *  @brief      arithmetic functions
 *
 *  @return     errorcode as int (0 is success)
 ****************************************************************************************/
int addition();
int subtraction();
int multiply();
int divide();

/*
 ****************************************************************************************
 *  @brief      duplicate the top element of the stack
 *
 *  @return     errorcode as int (0 is success)
 ****************************************************************************************/
int duplicate();

/*
 ****************************************************************************************
 *  @brief      swap the first two elements on the stack
 *
 *  @return     errorcode as int (0 is success)
 ****************************************************************************************/
int swap();

/*
 ****************************************************************************************
 *  @brief      print out the top element of the stack
 *
 *  @return     errorcode as int (0 is success)
 ****************************************************************************************/
int computing_print();

/*
 ****************************************************************************************
 *  @brief      print out all stack elements
 *
 *  @return     errorcode as int (0 is success)
 ****************************************************************************************/
int computing_printAll();

/*
 ****************************************************************************************
 *  @brief      convert an integer to a string 
 *
 *  @param      integer 
 *
 *  @return     pointer to the string
 ****************************************************************************************/
char* int_to_string (int);

#endif
// EOF