#include <iostream>
using namespace std;
class test{
    public:
    inline void kill(){
        cout<<"yes";
    }
};
double zerodiv(int x,int y){
    if(y==0)
     throw "zero_div_error";
    return (double)x/y;
}
int main(){
    test t1;
    t1.kill();
    int x,y;
    cin>>x>>y;
    try{
        cout<<zerodiv(x,y);
    }
    catch(const char* s){
        cout<<s;
    }
}