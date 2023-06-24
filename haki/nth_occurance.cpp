#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int s;
    cin>>s;
    int a[s];
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
     //input target and occurance
    int target,n;
    cin>>target>>n;
    int index,flag=0;
    unordered_map<int,int>m;
    for(int i=0;i<s;i++){
        m[a[i]]++;
        if(a[i]==target && m[a[i]]==n){
            flag=1;
            index=i;
        }
    }
    if(flag!=1)
    cout<<"Element Not found"<<endl;
    else
    cout<<"Element Occured at index "<<index<<endl;
   



}