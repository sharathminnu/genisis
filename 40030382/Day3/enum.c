#include<stdio.h>
#include <string.h>

#define SIZE 3

enum accountType{savings,current,salary,fd,Rd};

struct Account{
    int accountNo;
    char name[20];
    float balance;
    enum accountType type;

};

void init(struct Account* ptr,int accountNo,char name[],float balance,int i){
        (ptr+i)->accountNo = accountNo;
        strcpy((ptr+i)->name,name);
        (ptr+i)->balance = balance;
}

void display(struct Account* ptr){
    for(int i=0;i<SIZE;i++){
        printf("Account details of structure object %d\n",i);
        printf("%d\n%s\n%f\n",(ptr+i)->accountNo,(ptr+i)->name,(ptr+i)->balance);
    }
}

int filterByBalance(struct Account* ptr,float val){
    int count = 0;

    for(int i =0;i<SIZE;i++){
        if((ptr+i)->balance > val){
            count++;
            
        }
    }
    return count;
}

enum accountType getAccount(enum accountType* etr,int index){


}



int main(){
    

    enum accountType *etr;
    enum accountType type;
    etr = &type; 

    typedef struct Account Account;
    Account *ptr = NULL;
    Account a[SIZE];
    ptr = a;
    float val = 5000.234;
    init(ptr,4321,"sharath",4000.3456,1);
    init(ptr,1234,"minnu",5000.3456,2);
    init(ptr,2345,"mithun",8000.3456,0);
    display(ptr);
    int x = filterByBalance(ptr,val);
    printf("%d\n",x);


}