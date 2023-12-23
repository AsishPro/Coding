#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> words={"word","good","best","word"};
    unordered_map<string,int> og;
        for(auto i:words){
            og[i]++;
        }
    // for(auto i:og){
    //         cout<<i.first<<" "<<i.second<<endl;
    // }
    string s="god";
    cout<<og[s];
    if(og[s]==0)
        cout<<"no f";
    else 
    cout<<'f';
    vector<int>res={};
    for(auto i:res){
        cout<<i;
    }
}