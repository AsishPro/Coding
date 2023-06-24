#include <stdio.h>
struct team{
    int a;
    int b;
    int c;
};
int main(){
    
    int n;
    scanf("%d",&n);
    struct team a[n];
    for(int i=0;i<n;i++){
      scanf("%d",&a[i].a);
      scanf("%d",&a[i].b);
      scanf("%d",&a[i].c);
    }
    int count=0;
    for(int i=0;i<n;i++){
    if(a[i].a!=0 && a[i].b!=0 ||a[i].b!=0 && a[i].c!=0 || a[i].a!=0 && a[i].c!=0){
        count++;
     }
    }
    printf("%d",count);
}