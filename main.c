#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"userinput.h"
#include"encrpyt.h"
//int total[100];
int main()
{
    int arr[10];
    int *n=user_input();
    int ref=fork();
    if(ref==0)
    {
        int *encrpytedarray=encrypt(n,2,arr);
        printf("%d\n %d\n",encrpytedarray[0],encrpytedarray[1]);
    }
    else if(ref>0)
    {
        //printf("%d\n %d\n",n[0],n[1]);
    }
    else 
    perror("fork");

   
    return 0;
}