#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];

int front = 0;
int rear = -1;
int item_count = 0;

void insert(int data){
    if(item_count == MAX_SIZE){
        printf("Queue overflow\n");
    }else{
        rear = (rear+1) % MAX_SIZE;
        queue[rear] = data;
        item_count++;
    }
}

int remove_data(){
    int data;

    if(item_count == 0){
        printf("Queue underflow\n");
        return -1;
    }else{
        data = queue[front];
        front = (front + 1) % MAX_SIZE;
        item_count--;
        return data;
    }
}

void print_queue(){
    int i;

    if(item_count == 0){
        printf("Queue empty\n");
    }else{
        for(i = 0; i < item_count; i++){
            int index = (front + i) % MAX_SIZE;
            printf("%d\n", queue[index]);
        }
    }
}

