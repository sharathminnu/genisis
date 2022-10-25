#include <stdio.h>
int total[100];
int *user_input(){
    printf("Enter your psnumber: \n");
    scanf("%d",&total[0]);
    printf("Enter the Option: \n1.Cast vote\n2.Results\n");
    scanf("%d",&total[1]);
    return total;
}

