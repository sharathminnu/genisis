#include <stdio.h>

void prime(int num){

    int count = 0;

    if(num == 0 || num == 1){
        count = 1;

    }

    for(int i=1;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }

    if(count == 2){
        printf("it is prime");
    }
    else{
        printf("it is not prime");
    }
}

int main(){
    int p;
    printf("enter the number:");
    scanf("%d",&p);
    prime(p);
}