#include <iostream> 
using namespace std;
class circle 
{ 
private: 
 int r; 
 float x, y; 
public: 
 circle( ) 
 { 
 } 

 circle(int rr, float xx, float yy ) 
 { 
 r = rr; 
 x = xx; 
 y = yy; 
 } 

 void operator =( circle & c ) 
 { 
 cout<< "Assignment operator invoked"<<endl; 
 r = c.r; 
 x = c.x; 
 y = c.y; 
 } 

 circle( circle & c ) 
 { 
 cout << endl << "copy constructor invoked"<<endl; 
 r = c.r; 
 x = c.x; 
 y = c.y; 
 } 

 void showdata( ) 
 { 
 cout << endl << "Radius = " << r; 
 cout << endl << "X-Coordinate=" << x; 
 cout << endl << "Y-Coordinate=" << y; 
 } 

} ; 
int main( ) 
{ 
 circle c1 ( 10, 2.5, 2.5 ); 
 circle c2(c1);
 circle c4; 
 c4=c2;
 circle c3;
 c3=c1; 
 c1.showdata( ); 
 c2.showdata( ); 
 c3.showdata( ); 
 c4.showdata( ); 
 return 0;
}