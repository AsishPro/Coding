#include <iostream>
using namespace std;
class complex{
    private:
    float real;
    float img;
    public:
    complex(){};
    complex(float a,float b){
      real=a;
      img=b;
    }
    complex operator+(complex o2){
        complex t;
        t.real=real+o2.real;
        t.img=img +o2.img;
        return t;
    }
    complex operator*(complex o2){
        complex t;
        t.real=real*o2.real-img*o2.img;
        t.img=real*o2.img+img*o2.real;
        return t;
    }
    void operator ++(){
          real++;
          img++;
    }
    void print(){
        cout<<real<<'+'<<img<<'i'<<endl;
    }
};
int main(){
    complex o1(2,3),o2(4,5);
    complex o3=o1+o2;
    o3.print();
    o3=o1*o2;
    o3.print();
    ++o1;
    o1.print();
}