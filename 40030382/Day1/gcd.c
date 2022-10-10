#include <stdio.h>  


void gcd(int n1,int n2){
        while (n1 != n2)   
    {  
       
        if (n1 > n2)  
            {  
            n1 = n1 - n2;   
            }  
           
        else  
            {  
                n2 = n2 - n1;  
                }     
                  
    }   
   
    printf( " GCD of two numbers  is %d.", n2); 
}
int main()  
{     
   
    int n1 = 96, n2 = 36; 
    gcd(n1,n2); 
 
}  