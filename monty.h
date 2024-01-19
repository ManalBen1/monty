// monty.h

#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

extern Stack stack;

void push(int value, int line_number);
int pop(int line_number);
void swap(int line_number);
void add(int line_number);
void pall(void);
void pint(int line_number);
void nop(void);

#endif /* MONTY_H */
