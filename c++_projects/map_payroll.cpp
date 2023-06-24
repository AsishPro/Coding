#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
using namespace std;
int c=0;
unordered_map<int,int>m;
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
    friend void search();
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
     cout<<m[o1.id]<<' '<<o1.id<<endl;
     file>>o1.name>>o1.age>>o1.exp>>o1.depart;
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
        file<<i+1<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
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
        cout<<"Enter the experience"<<endl;
        cin>>o1.exp;
        cout<<"Enter the Department"<<endl;
        cin>>o1.depart;
        o.push_back(o1);
    }
    c=c+n;
    update();
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
        cout<<o[i].id<<' '<<o[i].name<<' '<<o[i].age<<' '<<o[i].exp<<' '<<o[i].depart<<endl;
         i++;
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
    cout<<c<<endl;
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