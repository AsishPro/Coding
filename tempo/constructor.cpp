#include<stdio.h>

#include<iostream>

using namespace std;

class vol

{

    int l;

    int b;

    int r;

    int h;

public:

vol(int a)

    {

        l=a;

    }

vol(int a,int b)

    {

        r=a;

        h=b;

    }

vol(int a,int d,int c)

    {

        l=a;

        b=d;

        h=c;

    }

void cube()

    {

        cout<<"Volume of Cube:  "<<l*l*l << endl;

    }

void cyli() {

            cout<<"Volume of Cylinder: "<<3.14*r*r*h <<endl;

        }

            void rec()

            {

                cout<<"Volume of Rect.Box:  "<<l*b*h << endl;

            }

};

int main()

{
    vol x(5);
    vol v1(2);

    v1.cube();

    vol v2(3,4);

    v2.cyli();

    vol v3(1,2,3);

    v3.rec();

}