#include <stdio.h>
#include <string.h>



void vc(char s[]){
    int c = 0;
    int v = 0,con =0;
    while (s[c] != '\0') {
    if (s[c] == 'a' || s[c] == 'A' || s[c] == 'e' || s[c] == 'E' || s[c] == 'i' || s[c] == 'I' || s[c] =='o' || s[c]=='O' || s[c] == 'u' || s[c] == 'U'){
        v++;
    }
    else{
        con++;

    }
      
    c++;
   

}
printf("Vowels in string is %d\n",v);
int a = con-1;
printf("Consonents in string is %d\n",a);
}

int main(){
    char s[50];
    printf("Enter the string:");
    fgets(s,20,stdin);
    vc(s);


}