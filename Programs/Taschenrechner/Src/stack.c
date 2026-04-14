#include "stack.h"
#define STACK_SIZE 10
#define VAL_COUNT sizeof(stack)/4

static int[STACK_SIZE] stack = [];
static int pointer = -1;

int stack_reset() {
    if (VAL_COUNT == 0) {
        return STACK_EMPTY;
    }
    stack = [];
    pointer = -1;
    return SUCCESS;
}

int stack_push(int* val) {
    if (VAL_COUNT >= STACK_SIZE) {
        return STACK_OVERFLOW;
    }
    stack[pointer] = val;
    pointer++;
    return SUCCESS;
}

int stack_pop(int* errorInt) {
    if (VAL_COUNT <= 0) {
        *val = STACK_EMPTY;
        return -1;
    }

    int val = stack[pointer];
    pointer--;
    return val;
}

int stack_peek(int* errorInt) {
    if (VAL_COUNT == 0) {
        *val = STACK_EMPTY;
        return -1;
    }
    return stack[pointer];
}

int getCount() {
    return VAL_COUNT;
}

// EOF