#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int n;
	while(t--){
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++)
	     cin>>a[i];
	   int diff=abs(a[0]-a[1]);
	   int ans = INT_MAX;
       for(int i=0;i<n;i++){
            diff=0;
            if(i-1>=0)
            diff=max(diff,abs(a[i-1]-a[i]));
            if(i+1<n)
            diff=max(diff,abs(a[i+1]-a[i]));
            ans=min(ans,diff);
        }
	   cout<<diff<<endl;
	}
	return 0;
}
