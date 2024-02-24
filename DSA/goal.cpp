#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        
        int max=-999;
        int res=0;
        for(int i=0;i<22;i++){
            int a,b;
            cin>>a>>b;
            if ((a*1+b*20)>max){
                res=i+1;
                max=a*1+b*3;
            }
        }
        cout<<res<<endl;        
    }
}
