#include <stdio.h>
#include <stdlib.h>
#include "listtest.h"
int main(){
    int loc,item,ch;
    while(1){
    printf("\n\nEnter the Choice for Link list\n1.Insert \n2.Insert at Position\n3.Get data at Given Position\n4.Remove at Insert Position\n5.Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
         printf("Enter the data item:");
         scanf("%d",&item);
        addelement(item);
        break;
        case 2:
        printf("Enter the Position to Insert:");
        scanf("%d",&loc);
        printf("Enter the data item:");
        scanf("%d",&item);
        addElementAt(loc,item);
        break;
        case 3:
        printf("Enter the position to Display Data:");
        scanf("%d",&loc);
        getElement(loc);
        break;
        case 4:
        printf("Enter the position to Remove element:");
        scanf("%d",&loc);
        removeElementAt(loc);
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("Enter Valid Input!");
    }
}
}
