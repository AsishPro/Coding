#include <iostream>
using namespace std;
template <class t>
class B{
       private:
       t a,b;
       public:
       B(){
       }
       B(t a,t b){
        this->a=a;
        this->b=b;
       }
       void print(){
        cout<<a<<' '<<b;
       }
};
int main(){
    B <float>o1(2.5,5.7);
    o1.print();
}