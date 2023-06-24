#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int res=-1;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        res=-1;
        if(a>=c||b<=c||b>=a)
        cout<<-1<<endl;
        else{
         for(int i=1;i<pow(2,30);i++){
             if(((a^i)<(b^i))and((b^i)<(c^i))){
                 res= i;
                 break;
             }
          }
          cout<<res<<endl;
        }

    }
  return 0;
}