#include <iostream>
#include <vector>
using namespace std;
int  canSum(int target,vector<int>&a,vector<int>&ans, vector<vector<int>>&temp){
  if(target==0){
    temp.push_back(ans);
    return true;
  }


  for(int j=0;j<a.size();j++){
      if(target-a[j]>=0){
        ans.push_back(a[j]);
        canSum(target - a[j], a, ans, temp);
        ans.pop_back();
      }
  }

  return false;
}

int main(){
  vector<int>a={5,3};
  vector<int>ans;
  vector<vector<int>>temp;
  int t=25;
  canSum(25,a,ans,temp);
  for(auto i:temp){
    for(auto j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}