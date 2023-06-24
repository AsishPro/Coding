#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<string>a;
    string s;
    for(int i=0;i<5;i++){
        cin>>s;
        a.push_back(s);        
    }
    cout<<a[3][1];
    
}