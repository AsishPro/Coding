#include <iostream>
using namespace std;
template<class T,class k>
T add(T &a,k &b)
{
k result = a+b;
return result;

}
int main()
{
int i =2;
float m = 2.3;
cout<<"Addition of i and j is :"<<add(i,m);
return 0;
}