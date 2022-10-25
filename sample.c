#include<stdio.h>
#include<unistd.h>
#include"userinput.h"
#include"encrpyt.h"
//int total[100];
int main()
{
    int arr[100];
    int *n=user_input();
    int ref=fork();
    if(ref==0)
    {
        en
        
        //printf("1");
    }
    else if(ref>0)
    {
        printf("%d %d",n[0],n[1]);
    }
    else 
    perror("fork");

    return 0;
}