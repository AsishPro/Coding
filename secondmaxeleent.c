#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int temp,item=0;
    for(int i=0;i<n;i++){
       if(a[i]>item){
           temp=item;
           item=a[i];
       }
    }
    printf("%d",temp);
}