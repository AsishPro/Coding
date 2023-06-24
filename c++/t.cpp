#include <iostream>                                                                                                                                                                                          #include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    int n;
    while (t--){
       cin >> n;
    int t1=1,t2=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t1<=n*n){
                cout<<t1<<" ";
                t1+=2;
            }
            else{
                cout<<t2<<" ";
                t2+=2;
            }
        }
        cout << endl;
      }
    }
    return 0;
}