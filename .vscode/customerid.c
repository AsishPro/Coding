#include <stdio.h>
#include <stdlib.h>
int static k=0;
struct customerorder{
    char name[50];
    int phno;
    int orderid;
    char itemnam[50];
    struct customerorder *link;
};
struct customerorder *head;

void display(){
    struct customerorder *temp=head;
    while(temp!=NULL){
    printf("\nCustomer name:%s",temp->name);
    printf("\nCustomer phone Number:%d",temp->phno);
    printf("\nOrder Id:%d",temp->orderid);    //unique id for everycustomer - k is global
    printf("\nOrder item:%s\n",temp->itemnam);
    temp=temp->link;
    }
}
void list(){
    struct customerorder *ptr=(struct customerorder*)malloc(sizeof(struct customerorder));
    printf("Enter the Name of Customer: ");
    scanf("%s",ptr->name);
    printf("Enter the phone Number: ");
    scanf("%d",&ptr->phno);
    ptr->orderid=++k;    //unique id for everyorder - k is global
    printf("Enter the item Name: ");
    scanf("%s",ptr->itemnam);
    if(head==NULL){
        head=ptr;
        ptr->link=NULL;
    }
    else{
        ptr->link=head;
        head=ptr;
    }
}
int main(){
    struct customerorder c[10];
    int n,x,ch;
    while(1){
    printf("\n1.Enter the Customer Details\n2.Display Current Customer List\n3.Exit");
    printf("\nEnter the Choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        list();
        break;
       case 2:
       display();
       break;
       case 3:
       exit(0);
       break;
       default:
       printf("\nEnter a Valid Option!\n");
    }
    }
} 