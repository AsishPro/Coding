#include<iostream>
using namespace std;
class circle
{ 
    float x,y;
    int r;
    public:
    circle()
    {
    }
    circle(int a,float b,float c)
    {
        r=a;
        x=b;
        y=c;
    }
    circle(circle c)
    {
        cout<<"copy constructor invoked"<<endl;
        r=c.r;
        x=c.x;
        y=c.y;
    }
    void operator =(circle &c)
    {
        cout<<"Assignment operator invoked"<<endl;
        r=c.r;
        x=c.x;
        y=c.y;
    }
    void display()
    {
        cout<<"Radius = "<<r<<endl;
        cout<<"X-Coordinate="<<x<<endl;
        cout<<"Y-Coordinate="<<y<<endl;
    }
};
int main()
{
    int a;
    float b,c;
    cin>>a;
    cin>>b>>c;
    circle c1(a,b,c);
    circle c2(c1);
    circle c3;
    c3=c1;

 cout<<endl;
    c1.display();
    // c2.display();
    // c3.display();
    // c4.display();
    return 0;
}