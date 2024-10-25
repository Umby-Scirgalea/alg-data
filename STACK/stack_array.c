#include <stdio.h>
#include <stdbool.h>

int MAX_SIZE = 10;

int stack[10];

int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == MAX_SIZE-1;
}

void push(int value){
    if(isFull()){
        printf("Stack full\n");
        return;
    }

    top++;
    stack[top] = value;
}

int pop(){
    if(isEmpty()){
        printf("Stack empty\n");
        return 0;
    }

    int value = stack[top];
    top--;
    return value;
}



