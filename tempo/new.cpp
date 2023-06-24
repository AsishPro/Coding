#include <iostream>
using namespace std;

class A{
     int a;
     double b;
     public:
     A(int x,double y){
         a=x;
         b=y;
     }
};

class B:public A{
    public:
    B(int a,int b):A(a,b){
        cout<<"Running"<<endl;
    }
};
int main(){
    B obj(2,3.4);

}