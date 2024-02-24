#include <iostream>
using namespace std;

class A{
    public:
    virtual void print(){
        cout<<"Class A"<<endl;
    }
};
class B: public A {
    public:
    void print(){
       cout<<"Class B"<<endl;
    }
};


//this is CALLED VIRTUAL FUNCTION(placeholder function) as it happeens during runtime 
//occurs with combined polymorphism and inheritance 
//can be accessed only using pointers

int main(){
    A *p;
    B obj;

    p=&obj;
    p->print();

}