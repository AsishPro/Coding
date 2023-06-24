#include <iostream>
using namespace std;
class A{

    int a=50;
    public:
    void dis(){
        cout<<endl;
        cout<<a;
    }
    friend void max(A &,class B &);
};
class B{
    int b=100;
    public:
    friend void max(A &,B &);
};
void max(A &o1,B &o2){
    int t=o2.b;
    o2.b=o1.a;
    o1.a=t;
    cout<<o1.a<<' '<<o2.b;
}
int main(){
    A o1;
    B o2;
    max(o1,o2);
    o1.dis();
}