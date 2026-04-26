#include "tests.h"
#include "stack.h"
#include "computing.h"
#include "errorHandling.h"

void testAll() {
    checkAdditionOverflow();

    checkAdditionUnderflow();

    checkSubtractionOverflow();

    checkSubtractionUnderflow();

    checkMultiplikationOverflow();

    checkMultiplikationUnderflow();

    checkZeroDivision();

    checkDivisionOverflow();

    checkStackOverflow();

    checkStackUnderflow();
}

void checkAdditionOverflow() {
    stack_push(INT_MAX);
    stack_push(1);
    handleError(addition());

    stack_push(INT_MAX);
    stack_push(100);
    handleError(addition());
}

void checkAdditionUnderflow() {
    stack_push(INT_MIN);
    stack_push(-1);
    handleError(addition());

    stack_push(INT_MIN);
    stack_push(-100);
    handleError(addition());
}

void checkSubtractionOverflow() {
    stack_push(INT_MAX);
    stack_push(-1);
    handleError(subtraction());

    stack_push(INT_MAX);
    stack_push(-100);
    handleError(subtraction());
}

void checkSubtractionUnderflow() {
    stack_push(INT_MIN);
    stack_push(1);
    handleError(subtraction());

    stack_push(INT_MIN);
    stack_push(100);
    handleError(subtraction());
}

void checkMultiplikationOverflow() {
    stack_push(INT_MIN);
    stack_push(-1);
    handleError(multiply());

    stack_push(-1);
    stack_push(INT_MIN);
    handleError(multiply());    
}

void checkMultiplikationUnderflow() {
    stack_push(INT_MAX);
    stack_push(-2);
    handleError(multiply());

    stack_push(2);
    stack_push(INT_MIN);
    handleError(multiply());      
}

void checkZeroDivision() {
    stack_push(2141);
    stack_push(0);
    handleError(divide());     
}

void checkDivisionOverflow() {
    stack_push(INT_MIN);
    stack_push(-1);
    handleError(divide());       
}

void checkStackOverflow() {
    int i = 1;
    for (int j = 0; j < 16; j++) {
        handleError(stack_push(i++));
        computing_print();
    }
}

void checkStackUnderflow() {
    int i;
    handleError(stack_pop(&i));
}
//EOF
