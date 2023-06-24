#include <iostream>
using namespace std;
class A{
    private:
    int height=20;
};

class B:public A{
    public :
    void print(){
        cout<<height;
    }
};
int main(){
    B o1;
    o1.print();
}