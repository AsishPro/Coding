#include <iostream>
using namespace std;
class A{
    public:
   int x=5;
   void asis();
};
void A::asis(){
   cout<<x;
}
int main(){
     A o1;
     o1.asis();
}