#include <bits/stdc++.h>
using namespace std;

int triangle(vector<vector<int>>tr,int i,int j,int n){
    
    if(i==n){
        return 0;
    }
    int left=triangle(tr,i+1,j,n);
    int right=triangle(tr,i+1,j+1,n);
    return tr[i][j]+max(left,right);
}
int main() {
    
    int t;
    cin>>t;
    int n;
    
    while (t--){
        cin>>n;
        vector<vector<int>>tr(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int temp;
                cin>>temp;
                tr[i].push_back(temp);
            }
        }    
        
       cout<<triangle(tr,0,0,n)<<endl;
        
    }
    return 0;
}
