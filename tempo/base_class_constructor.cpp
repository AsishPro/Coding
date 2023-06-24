#include <iostream>
using namespace std;
class A {
int a ;
int b ;
  public:
  A(int x,int y){
     a=x;
     b=y;
  }
  int mul() {
    int c = a*b;
    return c;
  }
};
class B : private A {
   public:
   B(int a,int b):A(a,b){}
   void display() {
    int result = mul();
    std::cout <<"Multiplication of a and b is : "<<result<< std::endl;
   }
};
int main() {
B b(10,20);
b.display();
return 0;
}