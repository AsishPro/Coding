#include <stdio.h>
#include <stdlib.h>
int n;
struct passenger{
    char name[50];
    int pnr;
    char type[10];
};
struct passenger s[100];
void pass(){
     printf("Enter the Number of Passengers: "); //as it is not link list
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         printf("\nEnter the Name of Passenger %d: ",i+1);
         scanf("%s",s[i].name);
         printf("\nEnter the PNR number(without symbols): ");
         scanf("%d",&s[i].pnr);
         printf("\nEnter the Ticket Type(1A/2A/3A/SL/GN): ");
         scanf("%s",s[i].type);
     }
}
void search(){
    int nr;
    printf("\nEnter the PNR to search: ");
    scanf("%d",&nr);
    for(int i=0;i<n;i++){
        if(nr==s[i].pnr){
          printf("\nName of Passenger 1:%s",s[i].name);
         printf("\nPNR number:%d",s[i].pnr);
         printf("\nTicket Type:%s",s[i].type);
         class(s[i].type);
         break;
        }
    }
}
void class(char a[10]){
    if(a[0]=='1'){
    printf("\nFirst Class");
    }
    else if(a[0]=='2'){
    printf("\nSecond Class");
    }
    else if(a[0]=='3'){
    printf("\nThird Class");
    }
    else if(a[0]=='S'){
    printf("\nSleeper Class");
    }
    else  
    printf("\nGeneral Class");
    
}
int main(){
    int ch;
    while(1){
    printf("\nEnter the Choice: ");
    printf("\n1.Add Passengers\n2.Search Passenger\n3.exit\n:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        pass();
        break;
        case 2:
        search();
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("\nEnter a Valid INput!");
    }
    }
}
