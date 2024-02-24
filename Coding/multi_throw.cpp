#include <iostream>
using namespace std;
void MyHandler()
{
try
{
throw "hello";
}
catch(char const*){
    cout<<"handler"<<endl;
    throw ; //rethows same
}
}

int main()
{
cout<< "Main start";
try
{
MyHandler();
}
catch(const char* s)
{
cout<<s;
cout <<"Caught exception inside Main\n";
}
cout << "Main end";
return 0;
}