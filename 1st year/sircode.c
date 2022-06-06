
#include<stdio.h>
#include<stdlib.h> // dynamic memory allocation
// this user defined queue for creating dynamic queue
struct dqueue {
    int data; // storing data
    struct dqueue *nxt; // storing next node reference
};

struct dqueue *head=NULL; // to store starting queue address [10, 20, 30] => []
// function for adding new element in queue towards the end of the queue
void addElement(int value) {
    struct dqueue *tptr = head;

    // allocting memory as new node
    //struct dqueue *node = (struct dqueue *)calloc(1,sizeof(struct dqueue)); // it will return adderss
    struct dqueue *node = (struct dqueue *)malloc(1*sizeof(struct dqueue)); 
    // assign incoming data
    node->data = value;
    // making new reference as null
    node->nxt = NULL;

    // adding element as fist node -- Starting
     if(tptr == NULL || head == NULL) {
        head = node; 
        return; // exiting from 
     } 
     // adding element as fist node -- Ending

    // adding element towards the end the queue -- Starting
     while(tptr->nxt!=NULL) { 
         tptr = tptr->nxt;
     }
    tptr->nxt = node;
    // adding element towards the end the queue -- End of logic
}
// displaying all the element in the queue
void displayQueue() {
    printf("[");
    struct dqueue *tptr = head;
    while(tptr) {
        printf("%d", tptr->data);
        if(tptr->nxt) 
            printf(",");
        tptr = tptr->nxt;
    }
    printf("]");
}
#include<stdio.h> // input and output operation
#include"queueUtil.h"

int main() {
    int opt = 1, value=0; // opt for selection operation in Queue. value for reading new data
    while(opt) { // list option for queue operation
        printf("\n1. Add element in Queue\n"); 
        printf("2. Display elements in Queue\n");
        printf("3. Search Element\n");
        printf("4. Length Queue\n");
        printf("0. Exit from Queue\n");
        scanf("%d", &opt); // selectin option 
        switch(opt) {
            case 1: // add operion
                printf("Queue Data ");
                scanf("%d", &value);  // reading data from user for queue
                addElement(value); // adding new element to queue
                break;
             case 2: // list operation
                displayQueue(); // this function to display all the data in queue
                break;
            case 3: // add operion
                printf("Queue Data to search");
                scanf("%d", &value);  // reading data from user for queue
                findElement(value); // adding new element to queue
                break;
             case 4: // list operation
                printf("Size of the Queue %d", length()); // this function to display all the data in queue
                break;
        }
    }
}
1. Write a code for remove and length for queue