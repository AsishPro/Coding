#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int d;
    scanf("%d",&d);
    d=(d%n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int j=0,key=0;
    for(int i=0;i<d;i++){
         j=0;
        key=a[j];
       for(j=0;j<n-1;j++){
           a[j]=a[j+1];
       }
       a[n-1]=key;       
     }
       for(int i=0;i<n;i++){
        printf("%d ",a[i]);
       }
     

     



}