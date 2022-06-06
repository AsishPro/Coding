#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void display(){
struct node *temp=head;
    if(temp==NULL){
        printf("\nQueue Underflow! Cannot Print\n");
    }
    else{
        printf("[");
     while(temp!=NULL){
       printf(" %d ",temp->data);
       temp=temp->next;
     }
     printf("]");
    }
}

void update(){
    struct node *lptr=head;
    int item,item2;
    printf("\nEnter the old item to Replace:");
    scanf("%d",&item);
    printf("\nEnter the new item to Replace Old item:");
    scanf("%d",&item2);
    while(lptr!=NULL){
        if(lptr->data==item){
            lptr ->data=item2;
        }
        lptr=lptr->next;
    }
    printf("\nList Updated");
}
void search(){
    struct node *lptr=head;
    int i=0,n;
    printf("Enter the item to search:");
    scanf("%d",&n);
    while(lptr->next!=NULL){
        i++;
        if(lptr->data==n){
            printf("Item Found at Location %d",i);
        }
        lptr=lptr->next;
    }
}
void queadd(){
    printf("\nEnter the item to insert:");
    int item;
    scanf("%d",&item);
    struct node *ptr,*t=head;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=ptr;
    }
    printf("\nNode Inserted Successfully");
    
}
void queremove(){
    struct node *r=head;
    if(head==NULL){
        printf("\nQue Empty Cannot Delete");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("\nSpace Freed! Node Deleted");
    }
    else{
        head=head->next;
        free(r);
        printf("\nNode Deleted Successfully");
    }
}
void quelength(){
    struct node *l=head;
    int i=0;
    while(l!=NULL){
        i++;
        l=l->next;
    }
    printf("\nLength of the Given Queue=%d",i);
}
int main(){
int ch;
  while(1){   //infinite loop exits if 2 is input 
  printf("\n\n1.Add element in Queue\n2.Remove Element in Queue\n3.Display Elements in Queue\n4.Display the length Queue\n5.Exit\n\nchoice: ");
  scanf("%d",&ch);
  switch(ch){
      case 1:
      queadd();
      break;
      case 2:
      queremove();
      break;
      case 3:
      display();
      break;
      case 4:
      quelength();
      break;
      case 5:
      exit(0);
      break;
      case 6:
      search();
      break;
      default:
      printf("\nEnter Valid Input");
    }
  }
}  