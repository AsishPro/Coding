#include <iostream>
using namespace std;
int fact(long long int n){
    if(n<=1)
    return 1;
    else
    return n*(fact(n-1));
}
int main(){
    for(long long int i=0;i<=4500;i++){
        cout<<i<<"!= "<<fact(i)<<' ';
    }
}