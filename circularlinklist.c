#include <stdio.h>
#include <stdlib.h>
#define max 5
int cqueue[max];
int front = -1, rear =-1;

void add(){
    int n;
    printf("Enter the Number to  Insert: \n");
    scanf("%d",&n);
    if((rear==(max-1)&&front==0)||(front==rear+1)){
        printf("\nOverflow");
        return;
    }
    else if(front==-1){
        front=0;
        rear=0; 
    }
    else if(rear==max-1)
       rear=0;
    else
     rear=rear+1;
    cqueue[rear]=n;
}
void delete(){
    if(front==-1){
         printf("Underflow");
         return;
    }
    printf("deleted element is %d",cqueue[front]);
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==max-1){
        front=(front+1)%max;
    }
    else
    front=front+1;
}
void display(){
    if(front==-1){
        printf("No elements");
        return;
    }
    if(front<=rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",cqueue[i]);
    }
    }
    else {
    for(int i=front;i<max;i++){
        printf("%d ",cqueue[i]);
    }int i=0;
    while(i<=rear){
        printf("%d ",cqueue[i]);
        i++;
    }
    }
}
int main ()
{
  int choice, item;
   while (1)
  {
      printf ("\n1.Insert\n");
      printf ("2.Delete\n");
      printf ("3.Display\n");
      printf ("4.Quit\n");
      printf ("Enter your choice : ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:	 	  add();	  break;
	case 2:	  delete();	  break;
	case 3:	  display();	  break;
	 case 4:            exit(1); 
	default:	  printf ("Wrong choice\n");
	}
    }
}