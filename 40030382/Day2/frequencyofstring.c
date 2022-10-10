#include <stdio.h>
#include <string.h>

void frequency(char s[],int len,char c){

    int count = 0;
    int a = 0;

    while(s[a] != 0){
        if(s[a] == c){
            count++;
        }
        a++;
    }
    printf("Character repeted %d\n",count);


}

int main(){
    char s[50];
    char c;
    int len = strlen(s);
    printf("Enter the string:");
    fgets(s,20,stdin);
    printf("Enter the character:");
    scanf("%c",&c);
    frequency(s,len,c);
}