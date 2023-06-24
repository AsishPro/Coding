#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    string s;
    cin>>s;

    int c1=0,c2=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R')
        c1++;
        else
        c2++;
        if(c1==c2 && (c1+c2)!=0){
            cout<<'(';
            for(int j=i-(c1+c2)+1;j<=i;j++)
               cout<<s[j];
            cout<<')';
            c1=0;
            c2=0;
        }   
    }
 

    return 0;
}