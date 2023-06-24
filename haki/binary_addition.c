#include <stdio.h>
int main(){
    long b1,b2;
    scanf("%ld%ld",&b1,&b2);
    int carry=0,sum=0;
    int i=0,r[20];
    while(b1!=0|b2!=0){
        r[i]=(b1%10+b2%10+carry)%2;
        carry=(b1%10+b2%10+carry)/2;
        b1=b1/10;
        b2=b2/10;   
         i++;
    }
    if(carry!=0)
    r[i]=carry;                        
    while(i>=0){
    printf("%d ",r[i]);
    i--;
    }
    
}