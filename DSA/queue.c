#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];

int front = -1;
int rear = -1;

void enqueue(int val){
    if(rear == SIZE-1){
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else{
        rear++;
        queue[rear] = val;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
    for(int i = front; i<rear+1;i++){
        printf("%d\n",queue[i]);
    }
    }

}

void peek(){
    printf("peek = %d\n",queue[front]);
}

int main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    enqueue(6);
    enqueue(7);
    display();
    enqueue(9);
    //display();
    dequeue();
    display();
    peek();
}