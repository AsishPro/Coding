#include <stdio.h>
int main(){
    int n;
    printf("Enter the Size of array: ");
    scanf("%d",&n);
    int a[n],x;
    for(int i=0;i<n;i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Number to search: ");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(x==a[i]){
            printf("Item found at location %d",i+1);
        }
    }
}