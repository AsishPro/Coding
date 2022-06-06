#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void addelement(int item){
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    temp=head;
    ptr->data=item;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }
    else{ 
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
    }
    printf("\nNode Inserted %d",ptr->data);
}

void addElementAt(int loc,int item){
    int i=0;
    struct node *ptr=(struct node *)malloc(sizeof(struct node)),*temp;
    temp=head;
    ptr->data=item;
    while(i<loc-2){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    printf("\nNode Inserted in position %d",i+2);
}
void getElement(int loc){
    struct node *temp;
    int i=0;
    temp=head;
    if(temp==NULL){
        printf("\nEmpty List No Nodes present");
    }
    else{
    while(temp->next!=NULL){
        i++;
        if(i==loc-1){
        printf("\nData present in location %d is %d\t",i,temp->data);
        break;
        }
        temp=temp->next; 
    }    
   }
}
void removeElementAt(int pos){
    struct node *p=head,*k;
      int i=1;
    if(head==NULL){
        free(head);
      printf("\nSpace Freed!");
    }
    else if(pos==1){
      head=head->next;
      p->next=NULL;
      free(p);
      printf("\nNode Deleted!");
    }
    else {
    while(i!=pos){
        k=p;
        p=p->next;
        i++;
    }
     k->next=p->next;
     p->next=NULL;
     free(p);
     printf("\nNode Deleted!");
    }
 }