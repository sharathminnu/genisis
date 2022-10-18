#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
     while(1){
        printf("process id is %d\n",getpid());
        sleep(1);
     }
}