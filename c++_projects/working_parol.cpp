#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int c=0;
class Employee{
    private:
    int id;
    char name[100];
    int age;
    int exp;
    char depart[100];
    public:
    friend void add(int );
    friend void saverecord();
    friend void readrec();
    friend void display();
    friend void modify();
    friend void del();
    friend void update();
};
vector<Employee > o;

void saverecord(){
     ofstream file("payo.txt",ios::app);
     for(int i=0;i<c;i++){
        file<<o[i].id<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
     }
     file.close();
}
void readrec(){
    
    c=0;
    ifstream file("payo.txt");
    if(!file)
    cout<<"No Records Saved-Add some Record"<<endl;
    else{
    Employee o1;
    while(file>>o1.id){
        cout<<o1.id<<' ';
     file>>o1.name>>o1.age>>o1.exp>>o1.depart;
     o.push_back(o1);
     c++;
     }
   }
   file.close();
}
void update(){
     ofstream file("payo.txt");
     for(int i=0;i<c;i++){
        file<<i+1<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
     }
     file.close();
}
void add(int n){
    int k=c+1;
    c=c+n;
    for(int i=0;i<n;i++){
        Employee o1;
        o1.id=k++;
        cout<<"Enter the Name:"<<endl;
        cin>>o1.name;
        cout<<"Enter the Age:"<<endl;
        cin>>o1.age;
        cout<<"Enter the experience"<<endl;
        cin>>o1.exp;
        cout<<"Enter the Department"<<endl;
        cin>>o1.depart;
        o.push_back(o1);
    }
    saverecord();
}
void del(){
     readrec();
     Employee temp[c];
     int id;
     cout<<"Enter the Employee id to modify: ";
     cin>>id;
     int index=-1;
     for(int i=0;i<c;i++){
      temp[i]=o[i];
      if(o[i].id==id)
      index=i;
     }
     if(index!=-1){
        for(int i=index;i<c-1;i++){
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
    // readrec();
    // int id;
    // cout<<"Enter the Employee id to modify: ";
    // cin>>id;
    // for(int i=0;i<c;i++)
    // if(o[i].id==id)
    // cout<<"Enter the "

}

void display(){
        readrec();
        int i=0;
        while(i<c){
        cout<<o[i].id<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
         i++;
        }     
}
int main(){
    int n;
    int ch;
    cout<<"1.Add an Employee\n2.Display\n3.Delete Record\nEnter the Choice :";
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
    cout<<c<<endl;
    break;
    }
    case 3:{
    del();
    break;
    }
    default:
    cout<<"default";
   }
  }
}