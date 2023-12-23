#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    
    string s="asish";
    int m=s.length();
    int n=3;
    vector<vector<int>> mat(m+1, vector<int>(n+1,0));
    for(auto i:mat){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}