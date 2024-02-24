#include <bits/stdc++.h>
using namespace std;
int GCD(int n, int m){
     int res=1;
    int max=1;
    int min=m>n?n:m;
    while(res<min){
        if(n%res==0 && m%res==0){
            if(res>max)
                max=res;
        }
        res++;
    }
    return max;
}
int main(){
   cout<<GCD(2,9);
}
