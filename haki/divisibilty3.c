#include <stdio.h>
int main(){
    int i=0,n;
    scanf("%d",&n);
    int a,b;
    while(i<n){
    scanf("%d%d",&a,&b);
    if(a%b==0)
    printf("0\n");
    else{
    //printf("%d\n",(((a/b)+1)*b)-a);
    printf("%d\n",b-(a%b)); 
     }   
        i++; 
  }

 
     // a/b * 
}