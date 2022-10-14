#include <stdio.h>
int main(int argc,char **argv)
{
    char ch;
    FILE *f=fopen(argv[1],"r");
    do{
         ch=fgetc(f);
         if(ch!=',')
         {
        printf("%c",ch);

        }
        
    }while(ch!=EOF);
    fclose(f);

    return 0;
}