
#include <stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

void push_front(int val);
void push_back(int val);
void pop_front();
void pop_back();
void insert_position(int val,int position);
void delete_position(int position);
void display();