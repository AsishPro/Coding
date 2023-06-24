#include <iostream>
#define INF 9999
using namespace std;
int a[100][100],d[100][100];
void floyd(int n){
    for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][k]+d[k][j]<d[i][j])
            d[i][j]=d[i][k]+d[k][j];
        }
      }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>a[i][j];
        d[i][j]=a[i][j];
        }
    }
    floyd(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]==9999)
            cout<<"INFI,";
            else
            cout<<d[i][j]<<", ";
        }
        cout<<endl;
    }
}