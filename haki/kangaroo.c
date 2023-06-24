#include <stdio.h>
int main(){
    int x1,v1,x2,v2;
    scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
    int count=0;
    while(v1<=10000||v2<=10000)
    {
        if(x1+v1==x2+v2){
        count++;
        printf("YES");
        break;
        }
        v1=v1+v1;
        v2=v2+v2;
    }
    if(count==0)
    printf("NO");
}