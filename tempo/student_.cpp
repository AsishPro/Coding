#include  <iostream>
using  namespace std;
class record{
    string name,reg;
    float m1,m2,m3,avg;
    public:
    void getdata(){
        cout<<"Enter the name:";
        cin>>name;
        cout<<"Enter the register no:";
        cin>>reg;
        cout<<"Ente 3 sub marks :";
        cin>>m1>>m2>>m3;
    }
    void cal(){
        avg=(m1+m2+m3)/3;
        cout<<"Average is :"<<avg<<endl;
    }
    void display(){
        cout<<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"reg :"<<reg<<endl;
        cout<<"Average :"<<avg<<endl;
        cout<<"Marks1 :"<<m1<<endl;
        cout<<"Marks2 :"<<m2<<endl;
        cout<<"Marks3 :"<<m3<<endl;
    }
};
int main(){
    record o1;
    o1.getdata();
    o1.cal();
    o1.display();
}