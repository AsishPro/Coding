#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=1534236469;
    int t=x;
    int res=0;
    while(t){
     
        res=res*10+(t%10);
        cout<<res<<endl;;
        t=t/10;
    }
    cout<<x<<endl;
    cout<<res<<endl;
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;
}