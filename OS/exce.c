#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*int main(int argc, char *argv[]){
    printf("PID of example.c = %d\n", getpid());
    char *args[] = {"Hello", "C", "Programming", NULL};
    execv("./hello", args);
    printf("Back to exce.c");
    return 0;
}*/

int main(){
    printf("PID OF EXCE.C IS %d\n",getpid());
    execv("./hello",);
}