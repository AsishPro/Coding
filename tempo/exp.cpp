#include <iostream>
using namespace std;
void MyHandler(){
try{
throw ("os","is","uk");
}
catch(char const* k){
    cout<<k;
    cout<<"handler"<<endl;
    throw ; //rethows same
}
}

int main()
{
cout<< "Main start"<<endl;
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