#include <stdio.h>
#include <string.h>
struct Student{
    int rollno;
    char name[20];
    float marks;

};

void init(struct Student* ptr,int rollno, char name[],float marks ){
    (*ptr).rollno = rollno;
    strcpy((*ptr).name,name);
    (*ptr).marks = marks;
    printf("%d %s %f\n",(*ptr).rollno,(*ptr).name,(*ptr).marks);


}

void display(struct student *ptr){

    printf("S1 ROLLNO: %d\n",(*ptr).rollno);
    printf("S1 NAME:%s\n", (*ptr).name);
    printf("S1 MARKS:%f\n",(*ptr).marks); 
}

void updateMarks(struct Student* ptr,float marks){
    (*ptr).marks = marks;
}

float getMarks(struct Student* ptr){
    float a = (*ptr).marks;
    return a;
}


int main(){
    typedef struct Student Student;
    Student s1;
    
    Student* ptr = &s1;
    init(ptr,23,"sharath",3.44);
    display(ptr);
    updateMarks(ptr,5.66);
    getMarks(ptr);
    display(ptr);
     
      




}