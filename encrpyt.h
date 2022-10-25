#include<stdio.h>
int *encrypt_message;
int *decrypt_meassage;
int *encrypt(int* message, int length,int *encrypt_message)
{
    encrypt_message [0]=message[0]+2;
    encrypt_message [1]+=message[1]+2;
    return encrypt_message;

}
int *decrypt (int* message, int length,int* decrypt_message){

    decrypt_message [0]=message[0]-2; 
    decrypt_message [1] +=message[1]-2;
    return decrypt_message;
}