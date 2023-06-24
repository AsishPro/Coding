#include<stdio.h> 
int main(){
    int z=0,d;
    int a=0;
    printf("Enter the Date of birth(DD/MM/YY):");
    scanf("%d",&d);
    while(d!=0){
     z=z+d%10;
     d=d/10;  
    }
    int sum=0,r;
    while(z/10!= 0){
      sum=0;
        while(z!= 0){ 
           r= z% 10;  
           sum=sum+r;  
           z=z/10; 
        }
        z=sum;
    }
    printf("\nsum=%d", sum);
    return 0;
}