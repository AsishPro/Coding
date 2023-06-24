#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
using namespace std;
int c=0;
unordered_map<int,int>m;

class Employee{
    private:
    int id,age,exp;
    int lop,grad=0;   //loss of pay
    char name[100],depart[100],design[100];
    float day,base,da,hra,ma,ta,special,pt,pf,ctc,net,tds;
    
    public:
    void grade();
    void grade1();
    void grade2();
    void grade3();
    void grade4();
    void grade5();
    friend void add(int );
    friend void saverecord();
    friend void readrec();
    friend void display();
    friend void modify();
    friend void del();
    friend void update();
    friend void search();
};
class Address{
    private:
    char address[100];
    
};
vector<Employee>o;

void readrec(){
    c=0;
    ifstream file("payo.txt");
    if(!file)
    cout<<"No Records Saved-Add some Record"<<endl;
    else{
    Employee o1;
    int i=0;
    while(file>>o1.id){
     m[o1.id]=o1.id;
     cout<<i<<' '<<m[o1.id]<<' '<<o1.id<<endl;
     file>>o1.name>>o1.age>>o1.exp>>o1.depart>>o1.design>>o1.grad;
     o.push_back(o1);
     i++;
     }
     c=i;
   }
   file.close();
}
void update(){
     ofstream file("payo.txt");
     for(int i=0;i<c;i++){
        file<<i+1<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<' '<<o[i].design<<' '<<o[i].grad<<endl;
     }
     file.close();
}

void add(int n){
    int k=c+1;
    for(int i=c;i<c+n;i++){
        Employee o1;
        o1.id=k++;
        cout<<"Enter the Name:"<<endl;
        cin>>o1.name;
        cout<<"Enter the Age:"<<endl;
        cin>>o1.age;
        cout<<"Enter the experience:"<<endl;
        cin>>o1.exp;
        cout<<"Enter the Department: "<<endl;
        cin>>o1.depart;
        cout<<"Enter the Designation: "<<endl;
        cin>>o1.design;
        cout<<"Select the Level(grade):\nGrade 1(Dean)\nGrade 2(proffesor)\nGrade 3(assistant proffesors,consultants)\nGrade 4(Staff)\nGrade 5(Warden and Managers)"<<endl;
        cin>>o1.grad;
        o1.grade();
        o.push_back(o1);
    }
    c=c+n;
    update();
    readrec();
}
void del(){
     Employee temp[c];
     int id;
     cout<<"Enter the Employee id to delete: ";
     cin>>id;
     if(m[id]!=0){
      for(int i=0;i<c;i++){
      temp[i]=o[i];
     }
     for(int i=m[id];i<c-1;i++){
            int k=o[i].id;
            o[i]=temp[i+1];
            o[i].id=k;
     }
     c--;
     cout<<"Employee Record Deleted";
     update();
     }
     else
     cout<<"Employee not found, Please Enter Valid id!"<<endl;
}

void modify(){
    if(c!=0){
    int id;
    cout<<"Enter the Employee id to modify: ";
    cin>>id;
    
    }
    else{
        cout<<"Add an employee to edit first"<<endl;
    }
}
void search(){
    int i=0;
     cout<<"Enter the Employee id to search: ";
     cin>>i;
     if(m[i]!=0){
     i=m[i]-1;
     cout<<o[i].id<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
     }
     else{
      cout<<"No Record Found with given id"<<endl;
         return ; 
     }
}
void display(){
        int i=0;
        if(c==0){
        cout<<"No Record Present Empty list"<<endl;
         return ;
        }
        while(i<c){
        cout<<o[i].id<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<' '<<o[i].design<<endl;
         i++;
        }     
}
void Employee::grade1(){
     grad=1;
     base=50000;
     day=base/30;
     da=0.32*base;
     hra=0.28*base;
     ma=0.06*base;
     ta=0.09*base; 
     special=0.25*base;
     pt=200;
     pf=(base+da)*0.12;
     ctc=base+da+hra+special+ma+ta;
     net=ctc-pf-pt;
     tds=(net*12);
    if(tds>500000)
    tds=12500+0.10*(tds);
    else
    tds=tds*0.05;
    cout<<ctc<<' '<<net<<' '<<tds;
}
void Employee::grade2(){
     grad=2;
     base=25000;
     day=base/30;
     da=0.32*base;
     hra=0.28*base;
     ma=0.06*base;
     ta=0.09*base; 
     special=0.25*base;
     pt=200;
     pf=(base+da)*0.12;
     ctc=base+da+hra+special+ma+ta;
     net=ctc-pf-pt;
     tds=(net*12);
    if(tds>500000)
    tds=12500+0.10*(tds);
    else
    tds=tds*0.05;
    cout<<ctc<<' '<<net<<' '<<tds;
}
void Employee::grade3(){
     grad=3;
     base=15000;
     day=base/30;
     da=0.32*base;
     hra=0.28*base;
     ma=0.06*base;
     ta=0.09*base; 
     special=0.25*base;
     pt=200;
     pf=(base+da)*0.12;
     ctc=base+da+hra+special+ma+ta;
     net=ctc-pf-pt;
     tds=(net*12);
    if(tds>500000)
    tds=12500+0.10*(tds);
    else
    tds=tds*0.05;
    cout<<ctc<<' '<<net<<' '<<tds;
}
void Employee::grade4(){
     grad=4;
     base=10000;
     day=base/30;
     da=0.32*base;
     hra=0.28*base;
     ma=0.06*base;
     ta=0.09*base; 
     special=0.25*base;
     pt=200;
     pf=(base+da)*0.12;
     ctc=base+da+hra+special+ma+ta;
     net=ctc-pf-pt;
     tds=(net*12);
    if(tds>500000)
    tds=12500+0.10*(tds);
    else
    tds=tds*0.05;
    cout<<ctc<<' '<<net<<' '<<tds;
}
void Employee::grade5(){
     grad=5;
     tds=0;
     base=5000;
     day=base/30;
     da=0.32*base;
     hra=0.28*base;
     ma=0.06*base;
     ta=0.09*base; 
     special=0.25*base;
     pt=200;
     pf=(base+da)*0.12;
     ctc=base+da+hra+special+ma+ta;
     net=ctc-pf-pt;
    cout<<ctc<<' '<<net<<endl;
}

void Employee::grade(){
    switch(grad){
        case 1:
        grade1();
        break;
        case 2:
        grade2();
        break;
        case 3:
        grade3();
        break;
        case 4:
        grade4();
        break;
        case 5:
        grade5();
        break;
    }
}

int main(){
    readrec();
    int n;
    int ch;
    cout<<"1.Add an Employee\n2.Display\n3.Delete Record\n4.Search an Employee\nEnter the Choice :";
  while(1){
    cin>>ch;
    switch(ch){
    case 1:{
    cout<<"Enter the Number of Employees to Add:";
    cin>>n;
    add(n);
    break;
    }
    case 2:{
    display();
    // cout<<c<<endl;
    break;
    }
    case 3:{
    del();
    break;
    }
    case 4:{
    search();
    break;
    }
    case 5:
    update();
    break;
    default:
    cout<<"default";
   }
  }
}