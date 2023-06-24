#include <stdio.h>
int main(){
    int i=0,x;
    scanf("%d",&x);
    int c[x];
    for(int i=0;i<x;i++){
        scanf("%d",&c[i]);
    }
    int k=0,n,count=0,a,b=1;
    while(i<x){
        a=c[i]-1;
        count=0;
        b=1;
        while(c[i]>b){
        count++;
        c[i]--;
        b++;
        }
        c[k]=count;
        k++;
        // printf("%d\n",count);
        i++;
    }
    for(int i=0;i<x;i++){
    printf("%d\n",c[i]);
    } 

}