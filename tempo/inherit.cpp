#include<iostream>
using namespace std;
class A
{
    public:
    int length,breadth;
    A(int l,int b)
    {length=l;
    breadth=b;
    }
    int multiply()
    {
        return length*breadth;
    }
};
class B:public A
{public:
     B(int a,int b):A(a,b){
     }
    void display()
    {
        cout<<multiply();
    }
};

int main()
{
  
   B b1(1,2);
    cout<<b1.multiply()<<endl;
    b1.display();
}