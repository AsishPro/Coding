#include <iostream>
#include <fstream>
using namespace std;
//ifstream - to read input from file
int main(){
    int a,b;
    char s[100];
    cin>>a>>b;
    cin.getline(s,100);  //includes space 
    //ios::out - write to file 
    ofstream file("asish.txt",ios::app); //directly opens file in write mode- deals with putting dat in file 
    //file.open("asish.txt"); 
    file<<a<<' '<<b<<s<<endl;
    file.close();
    // cout<<"Above is for writing"<<endl;
    int c,d;
    char a2[100];
    cout<<"Reading from file Started"<<endl;
    ifstream f2("asish.txt");  
    //directly opens file in read mode
    while(f2>>c>>d){
    f2.getline(a2,100); //text inside file will be filled in a2 - cannot read in new line
    cout<<c<<' '<<d;
    cout<<a2;
    cout<<endl;
    }
}