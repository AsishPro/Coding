#include <iostream>
using namespace std;
class over{
    private:
    int x,y;
    public:
    over(int a,int b){
        x=a;
        y=b;
    }
    void operator+(complex o1)
    friend over operator>>()
    void display(){
        cout<<x<<' '<<y;
    }
};
int main(){
    over o1(2,5);
    print(a<<b);
}