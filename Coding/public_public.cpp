#include <iostream>
using namespace std;
class Base{
    public:
    int data1,data2;
    public:
    Base(int a=0,int b=0):data1(a),data2(b){

    }
};
class Derived:public Base{
    public:
    void show(){
        cout<<"data 1 ="<<data1<<" data 2="<<data2;
    }
};
int main(){
    Derived d;
    d.show();
    return 0;
}