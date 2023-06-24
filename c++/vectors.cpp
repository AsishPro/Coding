#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> bill;
    
    int n,k,b;
    cin>>n>>k;
    int a;
        for(int i=0;i<n;i++){
            cin>>a;
            bill.push_back(a);
        }
    cin>>b;
    
     int sum=0;
      for(int i=0;i<n;i++){
          if(i!=k)
           sum=sum+bill[i];
      }
      if(b-sum>0)
      printf("%d",b-sum);
      else if(b==sum)
      printf("Bon Appetit");
}
