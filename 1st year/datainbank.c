#include <stdio.h>
#include <stdlib.h>
struct bank{
    int accnum;
    char name[50];
    int balance;
};
struct bank c[200];
void printData(int n){
    printf("\nCustomer List:\n");
    for(int i=0;i<n;i++){
        if(c[i].balance<100){
        printf("\nCustomer %d:\n",i+1);
       printf("Account Number:%d\n",c[i].accnum);
       printf("Name:%s\n",c[i].name);
       printf("Balance:%d\n",c[i].balance);
        }
    }
}
void deposit(int n){
   int item,num;
   printf("Enter the Account Number: ");
   scanf("%d",&num);
   for(int i=0;i<n;i++){
       if(c[i].accnum==num){
            printf("Enter the amount to Deposit: ");
            scanf("%d",&item); 
            c[i].balance=item+c[i].balance;
           }
   }
}
void withdrawl(int n){
   int item,num;
   printf("Enter the Account Number: ");
   scanf("%d",&num);
   for(int i=0;i<n;i++){
       if(c[i].accnum==num){
           if(c[i].balance>=100){
            printf("Enter the amount to Withdrawl: ");
            scanf("%d",&item); 
            c[i].balance=c[i].balance-item;
           }
           else{
               printf("\nInsufficient Balance Cannot Withraw");
           }
       }
   }
}
int main(){
    int n;
   printf("Enter the Number of Customers: ");
   scanf("%d",&n);
   for(int i=0;i<n;i++){
       printf("\nEnter the data of Customer %d:\n",i+1);
       printf("Enter the Account Number: ");
       scanf("%d",&c[i].accnum);
       printf("Enter the Name: ");
       scanf("%s",c[i].name);
       printf("Enter the Balance: ");
       scanf("%d",&c[i].balance);
   }
   int item,ch;
   printf("Enter the Choice:\n1.Print Accounts with <100 balance\n2.withdrawl\n3.Deposit\n4.exit\nchoice: ");
   switch(ch){
       case 1:
       printData(n);
       break;
       case 2:
       withdrawl(n);
       case 3:{
       printf("Enter the amount to Deposit: ");
       scanf("%d",&item);
       deposit(item);
       }
       break;
       case 4:
       exit(0);
       break;
       default:
       printf("\nEnter Valid Input");
   }
}


//code 2
