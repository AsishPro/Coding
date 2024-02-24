#include <iostream>
#include <vector>
using namespace std;
class prof{
    public:
    int id,sal;
    string name;
    public:
    prof(){};
    prof(int i,string s,int slr){
        id=i;
        name=s;
        sal=slr;
    }
    int greater(){
       if(sal>=20000) 
       return 1;
       return 0;
    }
    void print(){
        cout<<id<<' '<<name<<' '<<sal<<endl;
    }
    
};
vector<prof>o;
int main(){
    int n;
    cin>>n;
    int k,slr;
    string s;
    for(int i=0;i<n;i++){
        cin>>k>>s>>slr;
        o.push_back(prof(k,s,slr)); //making object and pushing
    }
    for(int i=0;i<n;i++){
        if(o[i].greater())
        o[i].print();
    }
}
    