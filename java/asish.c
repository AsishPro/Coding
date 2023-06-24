#include <stdio.h>
int sum(int r){
    int s=0;
    while(r%10!=0){
            s=s+(r%10);
            r=r/10;
        }
    return s;
}
int main(){
    int k,a;
    printf("Enter the Number to calcute sum:");
    scanf("%d",&a);
    k=sum(a);
    while(k>=10)
    k=sum(k);
    printf("Given Number = %d\n",a);
    printf("Calculated sum = %d",k);
}