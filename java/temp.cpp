#include <iostream>
using namespace std;

int main() {
  int t;
  cin>>t;
  int n;
  string s;
  string res="";
  while(t--){
      cin>>n>>s;
      int c=1;
     for(int i=1;i<n;i++){
        if(s[i-1]==s[i]) 
        c++;
        else{
            if(c&1) res+=s[i-1];
            else{
                res+=s[i-1];
                res+=s[i-1];
            }
            c=1;
        }
    }
    if(c&1)
    res+=s[n-1];
    else{
        res+=s[n-1];
        res+=s[n-1];
    }
    cout<<res<<endl;
  }
  return 0;
}
