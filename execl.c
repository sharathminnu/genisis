#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <stdlib.h>
int main(){
    int option;
    printf("Enter option");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            execl("./e3.out","1",NULL);
            break;
        case 2:
            execl("./e3.out","2",NULL);
            break;
        case 3:
            execl("./e3.out","3",NULL);
            break;
        default:
            printf("INVALID");
    }
    

 return 0;
}