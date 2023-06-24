#include <bits/stdc++.h>
using namespace std;
vector<int> bankers(int n,vector<int>*alloc,vector<int>*need,int *available,int *status){
   cout<<endl;
     for(int i=0;i<n;i++){
       for(int j=0;j<3;j++)
            cout<<need[i][j]<<" ";
       cout<<endl;
    }
   bool exist=true;
   bool give=true;
   vector<int>seq;
   while(exist){
       exist=false;
       for(int i=0;i<n;i++){
         if(status[i]!=1){
          give =true;
          for(int j=0;j<3;j++){
             if(need[i][j]>available[j]){
                give=false;
                break;
             }
          }
          if(give){
            status[i]=1;
            exist=true;
            seq.push_back(i);
            for(int j=0;j<3;j++)
              available[j]+=alloc[i][j];
         }
        }
      }
   }
   int c=0;
   for(int i=0;i<n;i++){
      if(status[i]==1)
        c++;
   }
   if(seq.size()==n)
   return seq;
   else
   return {0};
}
void request(int n,int p,int *req,vector<int>alloc[],vector<int>need[],int available[]){
   bool give=true;
   for(int i=0;i<3;i++){
      if(req[i]>need[p][i] || req[i]>available[i]){
         give=false;
         break;
      }    
   }
   if(give){
     for(int i=0;i<3;i++){
       available[i]-=req[i];
       alloc[p][i]+=req[i];
       need[p][i]-=req[i];
     }
    int status[n]={0};
    vector<int>safe=bankers(n,alloc,need,available,status);
    if(safe.size()==n){
        cout<<"Request Granted"<<endl;
        for(auto i:safe)
         cout<<i<<" ";
    }
    else{
        cout<<"request cannot be granted"<<endl;
    }

   }
}
int main(){
    int n;
    cin>>n;
    // vector<vector<int>>max(n,vector<int>(3));
    // vector<int>* max = new vector<int>[n];
    vector<int>max[n]={ { 7, 5, 3 }, 
                   { 3, 2, 2 }, 
                   { 9, 0, 2 }, 
                   { 2, 2, 2 }, 
                   { 4, 3, 3 } }; 
    vector<int>alloc[n]={ { 0, 1, 0 }, 
                     { 2, 0, 0 }, 
                     { 3, 0, 2 }, 
                     { 2, 1, 1 }, 
                     { 0, 0, 2 } };
    vector<int>need[n];
    int available[3]={3,3,2};
    int status[n]={0};
   //  cout<<"max matrix"<<endl;
   //  for(int i=0;i<n;i++){
   //     for(int j=0;j<3;j++){
   //      int x;
   //      cin>>x;
   //      max[i].push_back(x);
   //     }
   //  }
   //  cout<<"Alloc matrix"<<endl;
   //  for(int i=0;i<n;i++){
   //     for(int j=0;j<3;j++){
   //      int x;
   //      cin>>x;
   //      alloc[i].push_back(x);
   //     }
   //  }
    for(int i=0;i<n;i++){
       for(int j=0;j<3;j++){ 
         need[i].push_back(max[i][j]-alloc[i][j]);
       }
    }
    int i;
    cout<<"Enter the process requestiing: ";
    cin>>i;
    int req[3];
    cout<<"Enter the resource requested: ";
    cin>>req[0]>>req[1]>>req[2];
    request(n,i,req,alloc,need,available);
  

    // vector<int>safe=bankers(n,alloc,need,available,status);
    // if(safe.size()==n){
    //   for(auto i:safe)
    //      cout<<i<<" ";
    // }
    // else
    //   cout<<"no safe seq";
    cout<<available[0];
}
