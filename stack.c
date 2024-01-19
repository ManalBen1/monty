// stack.c
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(int value, int line_number) {
    if (stack.top >= STACK_SIZE) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.stack[++stack.top] = value;
}

int pop(int line_number) {
    if (stack.top < 0) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    return stack.stack[stack.top--];
}

void swap(int line_number) {
    if (stack.top < 1) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = stack.stack[stack.top];
    stack.stack[stack.top] = stack.stack[stack.top - 1];
    stack.stack[stack.top - 1] = temp;
}

void add(int line_number) {
    if (stack.top < 1) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.stack[stack.top - 1] += pop(line_number);
}

void pall(void) {
    int i;
    for (i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.stack[i]);
    }
}

void pint(int line_number) {
    if (stack.top < 0) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack.stack[stack.top]);
}

void nop(void) {
    // Do nothing
}
