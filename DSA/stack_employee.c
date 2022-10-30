#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int top = -1;


struct employee{
    int ps_number;
    char name[20];
    char email[40];
};
struct employee emp[SIZE];

int isFull(){
    if(top == SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


void push(int ps_number,char* name,char *email){
    if(top == SIZE-1){
        printf("Stack is Full\n");
    }
    else{
        top++;
        emp[top].ps_number = ps_number;
        strcpy(emp[top].name,name);
        strcpy(emp[top].email,email);
    }
    

}

void pop(){
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        top--;
    }
}

void peek(){
    printf("peek data = %d %s %s\n",emp[top].ps_number,emp[top].name,emp[top].email);
}

void display(){
    for(int i=0;i<top+1;i++){
        printf("%d %s %s\n",emp[i].ps_number,emp[i].name,emp[i].email);
    }
}


int main(){
    push(40030382,"Sharath","sharath.vangapalli@ltts.com");
    push(40030383,"surya","surya@ltts.com");
    peek();
    display();
    pop();
    display();
    printf("%d",top);
    
}