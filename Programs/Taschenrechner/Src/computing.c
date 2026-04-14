#include "computing.h"
#include "stack.h"
#include "errorHandling.h"
#include "display.h"

#include <stdbool>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

static bool isNegative = false;

int addition() {
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 =! SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 =! SUCCESS) {
        return check2;
    }

    if (x > 0 && y > (INT_MAX - x)) {  //check overflow
        return INTEGER_OVERFLOW;
    }
    if (x < 0 && y < (INT_MIN - x)) { //check underflow
        return IN_MIN;
    }

    stack_push(x+y);
    return SUCCESS;
}

int substraction() {
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 =! SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 =! SUCCESS) {
        return check2;
    }

    if (y < 0 && x > (INT_MAX - y)) { //check underflow
        return INTEGER_UNDERFLOW;
    }
    if (y > 0 && x < (INT_MIN - y)) { //check overflow
        return INTEGER_OVERFLOW;
    }

    stack_push(y-x);
    return SUCCESS;
}

int multiply() {
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 =! SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 =! SUCCESS) {
        return check2;
    }

    if (x < 0 && y > (INT_MIN/x)) { //check underflow
        return INTEGER_UNDERFLOW;
    }
    if (x > 0 && y > (INT_MAX/x)) { //check overflow
        return INTEGER_OVERFLOW;
    }

    stack_push(y*x);
    return SUCCESS;
}

int divide() {
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 =! SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 =! SUCCESS) {
        return check2;
    }

    stack_push(y/x);
    return SUCCESS;
}

int duplicate() {
    int x;

    int check = stack_peek(&x);
    if (check != SUCCESS) {
        return check;
    }
    return stack_push(x);
}

int swap() {
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 =! SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 =! SUCCESS) {
        return check2;
    }

    stack_push(x);
    stack_push(y);
    return SUCCESS;
}
