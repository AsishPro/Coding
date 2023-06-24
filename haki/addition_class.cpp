#include <iostream>
using namespace std;
class asish{
   public:
   int a,b;
   void getdata(){
      cout<<"Enter a and b: ";
      cin>>a>>b;
   }
   int sum(){
      return a+b;
   }
   int subs(){
      if(a>b)
      return a-b;
      else 
      return b-a;
   }
   int multiply(){
      return a*b;
   }
   float div(){
      return (float)a/b;
   }
   int mod(){
      return a%b;
   }
   
};
int main(){
    asish o1;
    o1.getdata();
    cout<<"\nSum is "<<o1.sum()<<endl;
    cout<<"Difference is "<<o1.subs()<<endl;
    cout<<"Multiplication is "<<o1.multiply()<<endl;
    cout<<"Division is "<<o1.div()<<endl;
    cout<<"Modulus is "<<o1.mod()<<endl;
    return 0;
}
