#include <stdio.h>
int main(){
    int k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    int i=0,brw=0;
    int temp=0;
    while(i<w-1){
        temp=temp+k;
        k=k*2;
        if(k>n)
            brw=k-temp;
           // temp=n-temp;
           // brw=k-temp;
        }
        i++;
    }
    printf("%d",brw);
}