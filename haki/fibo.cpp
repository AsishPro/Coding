#include <iostream>
using namespace std;
int dp[5];
int fibo(int i){
    if(i<=1)
    return i;
    else if(dp[i]!=0)
    return dp[i];
    else{
    return dp[i]=fibo(i-1)+fibo(i-2);
    }
}
int main(){
    cout<<fibo(5);
}