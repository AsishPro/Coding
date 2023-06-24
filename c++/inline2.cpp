#include <iostream>
using namespace std;
inline void mul(float x,float y){
   cout<<x*y<<endl;
}
inline void div(double p,double q){
    cout<<(p/q)<<endl;
}
int main(){
    float a,b;
    double c,d;
    cin>>a>>b>>c>>d;
    mul(a,b);
    div(c,d);
}