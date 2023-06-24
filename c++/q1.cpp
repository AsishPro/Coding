#include <iostream>
using namespace std;
class operation{
    private:
    int a,b;
    public:
    int sq(){
            cin>>a;
        cout<<a*a;
    }
    int rec(){
        cin>>a>>b;
        cout<<a*b;
    }
    int circle(){
        cin>>a;
        cout<<(3.14)*a*a;
    }

};
int main(){
      operation o1;
      o1.sq();
      o1.circle();
}