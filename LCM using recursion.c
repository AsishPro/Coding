/*#include <stdio.h>
int main() {
    int N, M;
    printf("Enter two integers: ");
    scanf("%d %d",&N,&M);
    int k;
    if(N>M) 
    k=N;
    else
    k=M;    //checking for max of both numbers
    while(1){
        if(k%N==0 && k%M==0){        //divisible by both
            printf("The LCM of %d and %d is %d.",N,M,k);
            break;
        }
        else
        k++;
    }
}*/

#include <stdio.h>

int lcm(int N,int M);

int main()
{
    int N, M;
    printf("Enter two integers: ");
    scanf("%d %d",&N,&M);
    int k;
    if(N>M) 
    k=N;
    else
    k=M; 
    int z=LCM(N,M,k);
    printf("The LCM of %d and %d is : %d.",N,M,z);
   
}


int LCM(int N,int M,int k){  
while(1){
        if(k%N==0 && k%M==0){  
            return k;
        }
        else
        k++;
}
}