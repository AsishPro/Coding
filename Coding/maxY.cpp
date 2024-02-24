#include <iostream>
using namespace std;

void main() {
    int t=1;
    cin>>t;
    int n,c=0;
    while(t--){
        c=0;
        cin>>n;
        char s[n];
        cin>>s;
        for(int i=0;i<n;i++)
            if(s[i]=='1')
                c++;
        int z=n-c;
        int r=min(c,z);
        if(r%2==0)
        cout<<"Ramos"<<endl;
        else
        cout<<"Zlatan"<<endl;
    }
}
