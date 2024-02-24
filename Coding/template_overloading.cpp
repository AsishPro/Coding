#include <iostream>
using namespace std;
void fun(int a)
{
std::cout << "Value of a is : " <<a<< std::endl;
}
template<class X>
int fun(X b)
{
std::cout << "Value of b is : " <<b<< std::endl;
return 0;
}
int main()
{
fun(10);
fun("assisj");
return 0;
}