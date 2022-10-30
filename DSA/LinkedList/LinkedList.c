#include <stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

struct node *head = NULL;

void push_front(int val){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = val;
        head->next = NULL;
    }
    else{
        struct node* temp = NULL;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = val;
        temp->next = NULL;
        temp->next = head;
        head = temp;
    }
}

void push_back(int val){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = val;
        head->next = NULL;
    }
    else{
        struct node* temp = NULL,*current = NULL;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = val;
        temp->next = NULL;
        current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = temp;


    }
}

void pop_front(){
    if(head == NULL){
        printf("LinkedList is empty\n");
    }
    else{
        struct node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;

    }
}

void pop_back(){
    if(head == NULL){
        printf("LinkedList is already empty\n");
    }
    else if(head->next == NULL){
        free(head);
    }
    else{
        struct node* pen_ultimate = NULL, *ultimate = NULL;
        pen_ultimate = ultimate = head;
        while(ultimate->next!= NULL){
            pen_ultimate = ultimate;
            ultimate = ultimate->next;
        }
        pen_ultimate->next = NULL;
        free(ultimate);
        ultimate = NULL;
    }
}

void insert_position(int val,int position){
    struct node* current = head;
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    position--;
    while(position != 1){
        current = current->next;
        position--;
    }
    temp->next = current->next;
    current->next  = temp;
}

void delete_position(int position){
    struct node* previous = head;
    struct node* current = head;
    if(head == NULL){
        printf("LinkedList is empty\n");
    }
    else if(position == 1){
        head = current->next;
        free(current);
        current->next = NULL;   
    }
    else{
        while(position != 1){
            previous = current;
            current = current->next;
            position--;

        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

void display(){
    struct node* temp = head;
    if(head == NULL){
        printf("LinkedList is empty");
    }
    else{
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
}