#include <stdio.h>
struct employee{
    char n[50];
    char id[50];
    int age;
    int ct;
    char des[50];
    struct employee s[5];
};

int main(){
   int n;
   printf("Enter the Numnmber of EMployees");
   scanf("%d",&n);
   struct employee a[n];
   for(int i=0;i<n;i++){
   printf("Enter the Name:");
   scanf("%s",a[i].n);
   printf("Enter the designation:");
   scanf("%s",a[i].des);
   if(a[i].des=="manager"){
       for(int j=0;j<5;j++){
       printf("Enter the Subordinades of manager");
       printf("Enter the Subordinate %d id: ",i+1);
       scanf("%s",a[i].s[j].id);\
      int count=0;
       for(int z=0;z<n;z++){
        if(a[i].s[j].id==a[z].id){
            continue;
            count++;
        }
       }
       if(count==0){
        printf("Enter the age: ");
        scanf("%d",&a[i].s[j].age);
        printf("Enter the contact Number: ");
        scanf("%d",&a[i].s[j].ct);
        }
       }
   }
 }

}
