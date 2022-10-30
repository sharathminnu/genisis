#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

struct employee{
    int ps_number;
    char name[20];
    char email[40];
};
//struct employee *ptr = NULL;
struct employee emp[SIZE];
int front = -1;
int rear = -1;

void enqueue(int ps_number,char *name,char* email){
    if(rear == SIZE-1){
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        emp[rear].ps_number = ps_number;
        strcpy(emp[rear].name,name);
        strcpy(emp[rear].email,email);

    }
    else{
        rear++;
        emp[rear].ps_number = ps_number;
        strcpy(emp[rear].name,name);
        strcpy(emp[rear].email,email);

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
        printf("%d %s %s",emp[i].ps_number,emp[i].name,emp[i].email);
    }
    }

}

void peek(){
    printf("peek data = %d %s %s",emp[front].ps_number,emp[front].name,emp[front].email);
}

int main(){
    enqueue(40030382,"sharath","sharath.vangapalli@ltts.com");
    display();

    



}