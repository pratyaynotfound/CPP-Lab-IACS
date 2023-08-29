#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
static int top = -1;
char stack[MAX_SIZE];

void push(char a);
char pop(void);

#endif