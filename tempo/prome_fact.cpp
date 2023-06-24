#include <bits./stdc++.h>
#define ll long long int
using namespace std;
map<ll,ll>m;

ll prim(ll k){
    ll i=2,x=k;
    k=sqrt(k);
    if(x==1)
    return 0;
    while(i<=k){
        if(x%i==0)
           return 0;
        i++;
    }
    return 1;
}
void primefac(ll n){
    ll x=n;
    ll i=2;
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }   
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
}
int main(){
    ll n;
    cin>>n;
    primefac(n);
    map<ll, ll>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        //m.erase(min);
        cout <<itr->first <<' '<<itr->second<<endl;
    }
}