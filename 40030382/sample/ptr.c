#include<stdio.h>
int main()
{
    FILE* ptr = fopen("input.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    char buf[100];
    for(int i=0;i<15;i++)
    {
    if(fscanf(ptr, "%*s %*s %s ", buf)== 1)
    {
        printf("%s\n", buf);
    }
    }
    return 0;
}