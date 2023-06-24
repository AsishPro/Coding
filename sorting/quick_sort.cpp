#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}
int partition(int *p,int s,int e){
     int pivot=p[e];
     int i=s-1;
     for(int j=s;j<=e-1;j++){
        if(p[j]<pivot){
            i++;
            swap(p[i],p[j]);
        }
     }
     swap(p[i+1],p[e]);
     return i+1;
}
void quicksort(int *p,int s,int e){
    if(s<e){
        int pi=partition(p,s,e);
        quicksort(p,s,pi-1);
        quicksort(p,pi+1,e);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}