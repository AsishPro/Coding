#include <iostream>
using namespace std;
template <class t>
void func(){
    t x;
    cin>>x;
    cout<<x<<endl;
}
int main(){ 
   func<int>();
}