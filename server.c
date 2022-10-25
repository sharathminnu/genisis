#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"userinput.h"
#include"encrpyt.h"
int main()
{
    int arr2[]={125,3};
    int arr1[100];
    int ref = fork();
    if(ref==0)
    {
        int *decryptedarray=decrypt(arr2,2,arr1);
        printf("%d\n %d\n",decryptedarray[0],decryptedarray[1]);
    } 
    else if(ref>0)
    {
        //printf("%d\n %d\n",n[0],n[1]);
    }
    else 
       perror("fork");

   
    return 0;
}
    
