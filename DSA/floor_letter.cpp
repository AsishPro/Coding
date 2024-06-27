#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> letters={'c','f','j'};
    vector<int> l;
    for (auto i:letters){
        l.push_back(i-'a'+1);
        // cout<<l.back();
    }
    int low=0;
    int high=l.size()-1;
    char t='e';
    int target=t-'a';
    cout<<target<<endl;
    while(low<=high){
        int mid=(low+high)/2;
        if(l[mid]==target){
            cout<<mid<<" ";
            break;
        }
        else if(l[mid]<target){
            low=mid+1;
        }
        else
            high=mid-1;   
    }
    cout<<low;
}