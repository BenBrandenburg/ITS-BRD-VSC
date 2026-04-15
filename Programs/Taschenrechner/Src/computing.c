#include "computing.h"
#include "stack.h"
#include "errorHandling.h"
#include "display.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int addition() {
    if (stack_getCount() < 2) {
        return STACK_COUNT_1;
    }

    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 != SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 != SUCCESS) {
        return check2;
    }

    if (x > 0 && y > (INT_MAX - x)) {  //check overflow
        return INTEGER_OVERFLOW;
    }
    if (x < 0 && y < (INT_MIN - x)) { //check underflow
        return INTEGER_UNDERFLOW;
    }

    stack_push(x+y);
    return SUCCESS;
}

int substraction() {
    if (stack_getCount() < 2) {
        return STACK_COUNT_1;
    }

    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 != SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 != SUCCESS) {
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
    if (stack_getCount() < 2) {
        return STACK_COUNT_1;
    }
    
    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 != SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 != SUCCESS) {
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
    if (stack_getCount() < 2) {
        return STACK_COUNT_1;
    }

    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 != SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 != SUCCESS) {
        return check2;
    }

    if (x == 0) {
        return ZERO_DIVISION;
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
    if (stack_getCount() < 2) {
        return STACK_COUNT_1;
    }

    int x;
    int y;

    int check1 = stack_pop(&x);
    if (check1 != SUCCESS) {
        return check1;
    }
    int check2 = stack_pop(&y);
    if (check2 != SUCCESS) {
        return check2;
    }

    stack_push(x);
    stack_push(y);
    return SUCCESS;
}

int computing_print() {
    int i;
    char c[] = "\n";
    int check = stack_peek(&i);
    if (check != SUCCESS) {
        return check;
    }

    printStdout(int_to_string(i));
    printStdout(c);
    return SUCCESS; 
}

int computing_printAll() {
    int* ptr;
    int check = stack_topElemPtr(&ptr);
    if (check != SUCCESS) {
        return check;
    } 

    char c[] = "\n";

    for (int i = 0; i < stack_getCount(); i++) {
        printStdout(int_to_string(*(ptr - i)));
         printStdout(c);
    }

    printStdout(c);
    return SUCCESS;
}

char* int_to_string(int num) {
    static char str[12];  // enough for int (max 10 symbols) + sign + '\0'
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {   // add symbols to str reverted
        str[i++] = (num % 10) + '0';    // asccii for 0 + int = assci for int
        num /= 10;
    }

    if (isNegative) {   // add "-" if negative
        str[i++] = '-';
    }

    str[i] = '\0';

    // revert string again to 
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

char* char_to_string(char c) {
    static char str[2];
    str[0] = c;
    str[1] = '\0';
    return str;
}