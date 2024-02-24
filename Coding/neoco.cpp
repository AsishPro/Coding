#include <iostream>
#include <math.h>
using namespace std;
struct complex{
    float real;
    float img;
};
int main(){
    complex o1,o2;
    cin>>o1.real>>o1.img>>o2.real>>o2.img;
    cout<<"Sum = "<<o1.real+o2.real<<" + "<<o1.img+o2.img<<"i"<<endl;
    cout<<"Difference = "<<o1.real-o2.real<<" + "<<o1.img-o2.img<<"i"<<endl;

    float k=o2.real*o1.real-(o1.img*o2.img);
    float z=o1.real*o2.img+o1.img*o2.real;
    cout<<"Difference = "<<k<<" + "<<z<<"i"<<endl;

    k=o2.real*o1.real+(o1.img*o2.img);
    z=o1.img*o2.real-o1.real*o2.img;
    float sq=(o2.real*o2.real)+(o2.img*o2.img);
    cout<<"Division = "<<k/sq<<" + "<<z/sq<<"i"<<endl;

    cout<<"Modulus of first complex number = "<<sqrt(o1.real*o1.real+o1.img*o1.img)<<endl;
    cout<<"Modulus of first complex number = "<<sqrt(o2.real*o2.real+o2.img*o2.img)<<endl;
}   