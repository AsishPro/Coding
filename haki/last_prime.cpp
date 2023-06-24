#include <iostream>
using namespace std;
class asish{
   public:
    
  int prime(int a){
    int i=2,r=1,last=0,count=0;
    while(i<=a){
      count=0;
      r=2;
      while(i%r==0&&r<=i){
          count++;
      }
        if(count==1)
         last=i;
      i++;
    }
      return last;
   }
};
int main(){
    asish o1;
    int a;
    cin>>a;
    cout<<o1.prime(a)<<endl;
    return 0;
}