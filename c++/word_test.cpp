#include<bits./stdc++.h>
using namespace std;
int main(){
    vector<string>kill={"Asish","Manoj","Killua"};
    set<string>raj(kill.begin(),kill.end());
    string temp="Manoj";
    if(raj.find(temp)!=raj.end())
    cout<<distance(raj.find(temp),raj.end())<<endl;
         
}