#include <iostream>
using namespace std;
double zerodiv(double a,double b){
     if(b==0)
       throw "zero_div_error";
    return (a/b);
}
int main(){
    int a,b;
    cin>>a>>b;
    try{
    cout<<zerodiv(a,b);
    }
    catch(char const* s){
         cout<<s;
    }
}