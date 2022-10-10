#include <stdio.h>

void ls(int a[],int s,int k){

    for(int i=0;i<s;i++){
        if(a[i] == k){
            printf("The key element found at %ls",&a[i]);
            break;
        }
        else{
            printf("The key element not found\n");
            break;
        }
    }
}



int main(){

    int s,k;
    printf("Enter size of array:");
    scanf("%d",&s);
    
    int a[s];

    printf("Enter the elements in array:");

    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the key element :");
    scanf("%d",&k);

    ls(a,s,k);
   

   
}