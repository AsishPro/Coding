#include <iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    int b=0;
    while(k!=0){
       if(k%2==1)
       b++;
       k=k/2;
    }
    cout<<b;
} 