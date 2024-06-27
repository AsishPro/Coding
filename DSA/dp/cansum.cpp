#include <iostream>
#include <vector>
using namespace std;
int canSum(int target,vector<int>&a,vector<int>&ans){
  if(target==0){
    return true;
  }

  for(int j=0;j<a.size();j++){
      if(target-a[j]>=0)
        if(canSum(target-a[j],a,ans)){
          ans.push_back(a[j]);
          return true;
        }
  }

  return false;
}

int main(){
  vector<int>a={5,3,4,7};
  vector<int>ans;
  int t=7;
  cout<<canSum(7,a,ans)<<endl;
  for(auto i:ans){
    cout<<i<<" ";
  }
}