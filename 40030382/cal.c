#include <stdio.h>
typedef struct complex{
   float real;
   float imag;
} complex;

typedef struct fraction{
    int numerator;
    int denominator;
}fraction;

fraction f_addition(fraction num1,fraction num2){
   fraction temp;
   temp.numerator = (num1.numerator*num2.denominator)+(num2.numerator*num1.denominator);
   temp.denominator = num1.denominator * num2.denominator;
   return (temp);

}
fraction f_subtraction(fraction num1,fraction num2){
   fraction temp;
   temp.numerator = (num1.numerator*num2.denominator)-(num2.numerator*num1.denominator);
   temp.denominator = num1.denominator * num2.denominator;
   return (temp);

}
fraction f_multiplication(fraction num1,fraction num2){
   fraction temp;
   temp.numerator = num1.numerator * num2.numerator;
   temp.denominator = num1.denominator * num2.denominator;
   return (temp);

}
fraction f_division(fraction num1,fraction num2){
   fraction temp;
   temp.numerator = num1.numerator * num2.denominator;
   temp.denominator = num1.denominator * num2.numerator;
   return (temp);

}

complex c_addition(complex num1, complex num2){
   complex temp;
   temp.real = num1.real + num2.real;
   temp.imag = num1.imag + num2.imag;
   return (temp);
}

complex c_subtraction(complex num1,complex num2){
   complex temp;
   temp.real = num1.real - num2.real;
   temp.imag = num1.imag - num2.imag;
   return (temp);

}
complex c_mutipication(complex num1,complex num2){
    complex temp;
    temp.real = ((num1.real * num2.real)-(num1.imag * num2.imag));
    temp.imag =( (num1.real*num2.imag)+(num1.imag*num2.real));
    return (temp);


}
complex c_division(complex num1,complex num2){
   complex temp;
   temp.real = ((num1.real * num2.real)+(num1.imag * num2.imag))/((num2.real*num2.real)+(num2.imag*num2.imag));
   temp.imag = ((num1.imag*num2.real)-(num1.real*num2.imag)) / ((num2.real*num2.real)+(num2.imag*num2.imag));
   return (temp);

}

int main(){
   complex num1, num2, value;
   fraction f_num1,f_num2,f_value;

   int var,c_val,f_val;
   printf("select the operation\n1.Complex\n2.Fraction");
   scanf("%d",&var);
   if(var == 1)
   {
     printf("entering real and imag parts of first complex no:\n ");
     scanf("%f %f", &num1.real, &num1.imag);
     printf("entering real and imag parts of second complex no:\n ");
     scanf("%f %f", &num2.real, &num2.imag);
     printf("complex operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
     scanf("%d",&c_val);
   switch(c_val)
   {
      case 1:
         value = c_addition(num1, num2);
         printf("result = %.1f + %.1fi\n", value.real, value.imag);
         break;
      case 2:
         value = c_subtraction(num1, num2);
         printf("result = %.1f + %.1fi\n", value.real, value.imag);
         break;
      case 3:
         value = c_mutipication(num1, num2);
         printf("result = %.1f + %.1fi\n", value.real, value.imag);
         break;
      case 4:
         value = c_division(num1,num2);
         printf("result = %.1f + %.1fi\n", value.real, value.imag);
         break;
      default :
         printf("enter the correct options\n");

   }
  

   }
   else if (var == 2){
   printf("entering numerator and denominator parts of first fraction:\n ");
   scanf("%d %d", &f_num1.numerator, &f_num1.denominator);
   printf("entering numerator and denominator parts of second fraction:\n ");
   scanf("%d %d", &f_num2.numerator, &f_num2.denominator);
   printf("fraction operations:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
   scanf("%d",&f_val);

   switch(f_val){
      case 1:
         f_value = f_addition(f_num1,f_num2);
         printf("result = %d / %d\n",f_value.numerator,f_value.denominator);
         break;
      case 2:
         f_value = f_subtraction(f_num1,f_num2);
         printf("result = %d / %d\n",f_value.numerator,f_value.denominator);
         break;
      case 3:
         f_value = f_multiplication(f_num1,f_num2);
         printf("result = %d / %d\n",f_value.numerator,f_value.denominator);
         break;
      case 4:
         f_value = f_division(f_num1,f_num2);
         printf("result = %d / %d\n",f_value.numerator,f_value.denominator);
         break;
      default :
         printf("enter the correct options\n");
   }
}
else{
    printf("enter the correct operations\n");
}
   return 0;
}
