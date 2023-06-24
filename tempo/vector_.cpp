#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,temp;
    cin>>t;
    vector<vector<int>> value;
    vector<int>a[];
    for(int i=0;i<t;i++)
    {
        cin>>n;
        vector<int> x;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            x.push_back(temp);
        }
        value.push_back(x);
    }
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<value[i].size();j++)
        {
            cout<<value[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}