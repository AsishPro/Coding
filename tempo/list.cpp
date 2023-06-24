#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        cin>>x;
        v.push_back(x);
         
    }                   
    sort(v.begin(),v.end());
    for(int i:v)
    {
        cout<<i<<" ";
    }
   
}