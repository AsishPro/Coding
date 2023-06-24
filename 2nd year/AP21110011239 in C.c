#include <stdio.h>
int add(int x,int y){
    int z=x+y;
    return z;
}
int subs(int x,int y){
    int z;
    if(x>y)
    z=x-y;
    else
    z=y-x;

    return z;
}

int multiply(int x,int y){
    int z=x*y;
    return z;
}

float divide(int x,int y){
    float z=((float)x/y);
    return z;
}

int expo(int x,int y){
    int k=x;
    for(int i=0;i<y-1;i++){
        k=x*k;
    }
    return k;
}
int main(){

    int x,y;
    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);
    printf("\nAddition is %d\n",add(x,y));
    printf("Substraction is %d\n",subs(x,y));
    printf("Multiplication is %d\n",multiply(x,y));
    printf("Division is %f\n",divide(x,y));
    printf("x^y is %d\n",expo(x,y));
    printf("y^x is %d\n",expo(y,x));
    printf("Remainder when x/y is %d\n",x%y);
    printf("Remainder when y/x is %d\n",y%x);

   return 0;
}