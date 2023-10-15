#include <bits/stdc++.h>
using namespace std;
int main(){
    int V=5,E=4;
    cin>>V>>E;
    vector<int> adj[V];
    for (int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<"Adjacency List"<<endl;
    for(auto i:adj){
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}