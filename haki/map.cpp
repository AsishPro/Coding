#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int>k;
    for(int i=0;i<10;i++){
        k[i]++;
    }
    for(auto i:k){ 
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}