#include <stdio.h>
#include <stdlib.h>
struct node{
     int data;
     struct node *next;
};
struct node *head;
void push(){
    int n;
    printf("Enter the number of elements(nodes):");
    scanf("%d",&n);
     struct node *s=(struct node *)malloc(n*sizeof(struct node));
     head=s;
     for(int i=0;i<n;i++){
         printf("Enter the %d node data item:",i+1);
         scanf("%d",&(s+i)->data);
         (s+i)->next=(s+i+1);
     }
     (s+(n-1))->next=NULL;      //last node
}
void display(){
    struct node *temp;
    temp=head;
     printf("printing node data elements:\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main(){
    int ch;
    while(1){
    printf("\nEnter the Choice:");
    scanf("%d",&ch);
        switch(ch){
        case 1:
        push();
        break;
        case 2:
        display();
        break;
       default:
       printf("enter valid option");
       break;
    }
}
}