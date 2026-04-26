#ifndef TESTS_H
#define TESTS_H

// runs all tests; 16 errors 
void testAll();

// INT_MAX + 1
// INT_MAX + 100
static void checkAdditionOverflow();

// INT_MIN + (-1)
// INT_MIN + (-100)
static void checkAdditionUnderflow();

// INT_MAX - (-1)
// INT_MAX - (-100)
static void checkSubtractionOverflow();

// INT_MIN - (1)
// INT_MIN - (100)
static void checkSubtractionUnderflow();

// INT_MIN * (-1)
// (-1) * INT_MIN
static void checkMultiplikationOverflow();

// INT_MAX * (-2)
// (-2) * INT_MAX
static void checkMultiplikationUnderflow();

// 2141 / 0
static void checkZeroDivision();

// INT_MIN / (-1)
static void checkDivisionOverflow();

// fill stack (1-15) + 16th push
static void checkStackOverflow();

// pop on empty stack
static void checkStackUnderflow();

#endif
//EOF