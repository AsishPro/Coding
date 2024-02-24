#include <iostream>
using namespace std;
class complex{
    float real,img;
    public:
    complex(){
        cin>>real>>img;
    }
    void operator *(complex &o2){
        int c1,c2;
        c1=real*o2.real-img*o2.img;
        c2=real*o2.img+o2.real*img;
        cout<<c1<<"+"<<c2;
    }
};
int main(){
    complex o1,o2;
    2*3;
    o1*o2;
}