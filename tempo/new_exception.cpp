#include <iostream>
using namespace std;
class myexcep:public exception{
    public:
    char const* nois(){
      return "this is running";
    }
};
int main(){
    try{
        throw myexcep();
    }
    catch(myexcep &a){
        cout<<a.what();
        cout<<"doee";
    }
    cout<<endl;
}