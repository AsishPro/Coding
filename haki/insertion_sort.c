#include <stdio.h>
int main(){
    int n, i=0, j, key;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
       scanf("%d", &a[i]);
    }
    i=1;
    for(i=1;i<n;i++){
        key=a[i];
        for(j=i-1;(j>=0) && (a[j]>key);j--){
            a[j+1]= a[j]; 
        }
        a[j+1]=key;  
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }


}