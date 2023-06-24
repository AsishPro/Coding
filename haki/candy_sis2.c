#include <stdio.h>
int main(){
    int i=0,x;
    scanf("%d",&x);
    int n;
    while(i<x){
        scanf("%d",&n);
    if(n%2==0){
      printf("%d\n",(n/2)-1);
    }
    else 
    printf("%d\n",(n/2));
    i++;
    }
}