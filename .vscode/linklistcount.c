#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head;

void createnode(int item){
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=item;
    if(head==NULL){
        head=ptr;
        ptr->link=NULL;
    }
    else{
    ptr->link=head;
    head=ptr;
    }
}
int occurence(int x){
    struct node *temp=head;
    int count=0;
    while(temp!=NULL){
        if(temp->data==x){
        count++;
        }
        temp=temp->link;
    }
    return count;
}
int main(){
    int n,x,ch;
    while(1){
    printf("\n1.Enter Elements in List\n2.Find Occurence of an Element\n3.Exit");
    printf("\nEnter the Choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:{
        printf("Enter the Element to Insert in Link List: ");
        scanf("%d",&n);
        createnode(n);
       }
       break;
       case 2:{
           printf("Enter the Element to Find Occurance: ");
           scanf("%d",&x);
          printf("Element Occured : %d times in List\n",occurence(x));
       }
       break;
       case 3:
       exit(0);
       break;
       default:
       printf("\nEnter a Valid Option!\n");
    }
    }
}