#include "stack.h"
#include "errorHandling.h"
#define STACK_SIZE 15

static int stack[STACK_SIZE];
static int pointer = 0;

int stack_reset() {
    pointer = 0;
    return SUCCESS;
}

int stack_push(int val) {
    if (val > INT_MAX) {
        return INTEGER_OVERFLOW;
    }
    if (val < INT_MIN) {
        return INTEGER_UNDERFLOW;
    }
    if (pointer >= STACK_SIZE) {
        return STACK_OVERFLOW;
    }
    stack[pointer] = val;
    pointer++;
    return SUCCESS;
}

int stack_pop(int *ptr) {
    if (pointer <= 0) {
        return STACK_EMPTY;
    }

    *ptr = stack[pointer-1];
    pointer--;
    return SUCCESS;
}

int stack_peek(int *ptr) {
    if (pointer == 0) {
        return STACK_EMPTY;
    }
    *ptr = stack[pointer-1];
    return SUCCESS;
}

int stack_getCount() {
    return pointer;
}

int stack_topElemPtr(int **ptr) {
    if (pointer == 0) {
         return STACK_EMPTY;
    }
    *ptr  = &stack[pointer-1];
    return SUCCESS;
}

// EOF