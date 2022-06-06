#include <stdio.h>
int main(){
    int n;
    printf("Enter the Number of Elements in Array: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&a[i]);   
    }
    int i=0,left=0,right=n-1;
    int mid=(left+right)/2;
    int x,count=0;
    printf("Enter the Search item: ");
    scanf("%d",&x);
    while(left<=right){
    if(x<a[mid]){
        right=mid-1;
        mid=(left+right)/2;
    }
    if(x>a[mid]){
        left=left+1;
        mid=(left+right)/2;
    }
    if(x==a[mid]){
    printf("item Found at Location %d",mid+1);
    i++; 
    break;
    }  
}
if(i=0){
    printf("Element not Found in Array");
}
}