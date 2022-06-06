#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void insbeg(){
    int item;
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    temp=head;
    printf("Enter the data item1:");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }
    else{ 
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
        head=ptr;
    }
    printf("\nNode Inserted %d",ptr->data);
}
void insend(){
    int item;
    struct node *ptr=(struct node *)malloc(sizeof(struct node)),*temp;
    temp=head;
    printf("Enter the data item:");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }
    else{ 
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
    }
    printf("\nNode Inserted");
}
void insran(){
    int i=0,loc,item;
    struct node *ptr=(struct node *)malloc(sizeof(struct node)),*temp;
    temp=head;
    printf("Enter the data item:");
    scanf("%d",&item);
    ptr->data=item;
    printf("Enter the Position to Insert item:");
    scanf("%d",&loc);
    while(i<loc-2){
        i++;
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("\nNode Inserted in position %d",i+2);
}
void display(){
    struct node *temp;
    temp=head;
    if(temp==NULL){
        printf("\nEmpty List No Nodes present");
    }
    else{
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
     printf("%d",temp->data);
    }
    
}
int main(){
    int ch;
    while(1){
    printf("\nEnter the choice for circular Link list\n1.Insert at Begin\n2.Insert at end\n3.Insert at Random\n4.Display\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        insbeg();
        break;
        case 2:
        insend();
        break;
        case 3:
        insran();
        break;
        case 4:
        display();
        break;
        default:
        printf("Enter Valid Input!");
        
    }
}
}
