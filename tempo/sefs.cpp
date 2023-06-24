#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	int n,m,k,x;
	while(t--){
	    cin>>n>>m>>k>>x;
      if(x%((n*k)+m)==0)
      cout<<"yes"<<endl;
     else if(x%((n*k)+m)-(n*(k-1))>0)
      cout<<"yes"<<endl;
     else 
      cout<<"no"<<endl;
	}
	return 0;
}
