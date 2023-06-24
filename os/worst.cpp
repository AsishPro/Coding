#include <bits/stdc++.h>
using namespace std;
int waste(int k,vector<int>&b){
    int best=-1;
    for(int i=0;i<b.size();i++){
      if(best==-1 && b[i]>k)
           best=i;
      else if(b[i]>k && b[i]-k>(b[best]-k))
         best=i;
    }
    return best;
}
int main(){
    vector<int> block;
    int x=1;
    while(x!=-1){
       cin>>x;
       if(x==-1)
         break;
       block.push_back(x);
    }
    for(int i=0;i<block.size();i++)
      cout<<block[i]<<" ";
    cout<<endl;
    
    vector<int> r;
    x=1;
    while(x!=-1){
       cin>>x;
       if(x==-1)
         break;
       r.push_back(x);
    }
    for(int i=0;i<r.size();i++)
      cout<<r[i]<<" ";
    cout<<endl;


     vector<int> pos(r.size(),-1);
    for(int i=0;i<r.size();i++){
        pos[i]=waste(r[i],block);
    }

    for(int i=0;i<pos.size();i++){
        cout<<pos[i]+1<<" ";
    }

}