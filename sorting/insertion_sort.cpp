#include <iostream>
using namespace std;
void insertion_sort(int *p,int n){
     int j;
     for(int i=1;i<n;i++){
        int key=p[i];
        for(j=i-1;j>=0 && key<=p[j];j--){
               p[j+1]=p[j];
        }
        p[j+1]=key;
     }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertion_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}