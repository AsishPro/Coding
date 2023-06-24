#include <iostream> 
using namespace std;
class test 
{ 
 int code; 
 static int count; 
public: 
 test(){
  count++;
 }
 static void showcount(void) 
 { 
 cout<<"count:"<<count<<"\n"; 
 } 
}; 
int test :: count; 
int main() 
{
 test t1,t4;
 test::showcount(); 
 test t2; 
 test::showcount(); 

 return 0; 
} 
 