#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    fork();
    fork();
    wait();
    fork();
    printf("hello\n");
}