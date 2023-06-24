#include <stdio.h>
int main(){
    int n,b;
    scanf("%d%d",&n,&b);
    int a[n],count=0;
    for(int x=0;x<n;x++){
        scanf("%d",&a[x]);
       
    }

    for(int x=0;x<n;x++){
       if(a[x]>=a[b-1]&&a[x]>0)
          count++; 
       
    }

    
    printf("%d",count);
}