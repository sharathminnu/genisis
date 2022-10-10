#include <stdio.h>

void shape(int a,int b,int c){
    if(a == b && b == c){
        printf("it is equilaterial triangle");

    }
    else if (a == b || b == c || c == a)
    {
        printf("it is isosceles triangle");
    }
    else
    {
        printf("it is scalen triangle");

    }
    
}

int main(){
    int a,b,c;
    printf("enter the sides of triangle:");
    scanf("%d%d%d",&a,&b,&c);
    shape(a,b,c);
}