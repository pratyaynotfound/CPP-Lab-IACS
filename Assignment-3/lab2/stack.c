#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

void push(char a){
    if(top>=MAX_SIZE){
        printf("Stack Overflow!\n");
        exit(0);
    }
    stack[++top] = a;
}
char pop(void){
    if(top<-1){
        printf("Stack Underflow!\n");
        exit(0);
    }
    char a = stack[top--];
    return a;
}