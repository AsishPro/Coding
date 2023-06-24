#include <iostream>
#include <vector>
using namespace std;
int main(){
    
    int n,k,b;
    cin>>n>>k;
    int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    cin>>b;
    
     int sum=0;
      for(int i=0;i<n;i++){
          if(i!=k)
           sum=sum+a[i];
      }
      if(b-sum>0)
      cout<<b-sum;
      else if(b==sum)
      cout<<"Bon Appetit";
}
