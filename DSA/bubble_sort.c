#include <stdio.h>

int main(){
    int a[5] = {6,5,4,3,2};
    int temp =0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i=0;i<5;i++){
        printf("%d",a[i]);
    }
}