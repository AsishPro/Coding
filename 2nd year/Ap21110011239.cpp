#include <iostream>
using namespace std;
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
    cout<<"Enter two numbers: ";
    cin>>x>>y;
    cout<<"\nAddition is "<<add(x,y)<<endl;
    cout<<"Substraction is "<<subs(x,y)<<endl;
    cout<<"Multiplication is "<<multiply(x,y)<<endl;
    cout<<"Division is "<<divide(x,y)<<endl;
    cout<<"x^y is "<<expo(x,y)<<endl;
    cout<<"y^x is "<<expo(y,x)<<endl;
    cout<<"Remainder when x/y is "<<x%y<<endl;
    cout<<"Remainder when y/x is "<<y%x<<endl;

   return 0;
}