#include <stdio.h>
#include <string.h>

int main(){
    char s[20] = "sharath";

    int len;
    len = strlen(s);
    int start,end;
    start = 0;
    end = len - 1;
    int temp;
    
     for (int i=start; i <end; i++)  
    {  
        temp = s[i];  
        s[i] = s[end];  
        s[end] = temp;  
        end--;  
    } 

    printf("%s\n",s);
    
} 

