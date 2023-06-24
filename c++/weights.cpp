#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int w,a[3],flag=0;
    for(int j=0;j<n;j++){
        flag=0;
        cin>>w;
      for(int k=0;k<3;k++){
        cin>>a[k];
       }
          if(a[0]==w||a[1]==w||a[2]==w){
            flag=1;
            cout<<"YES\n";
          }
          else if(a[0]+a[1]==w||a[1]+a[2]==w||a[0]+a[2]==w){
              flag=1;
          cout<<"YES\n";
          }
          else if(a[0]+a[1]+a[2]==w){
                  flag=1;
                  cout<<"YES\n";
                  break;
           }
          if(flag==0)
          cout<<"NO\n";
        //   cout<<endl<<j;
    }
	return 0;
}
