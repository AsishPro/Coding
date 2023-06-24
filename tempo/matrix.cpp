#include <iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int sum=0,count=0;
    for(int j=0;j<n;j++){
        count=0;
        for(int i=0;i<m;i++){
           if(a[i][j]==1)
           count++;
        }
        count=(count*(count-1))/2;
        sum+=count;
    }
    cout<<sum;
}