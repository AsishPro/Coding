#include <iostream>
using namespace std;
void merge(int *p,int s,int mid,int e){
    int s1=mid-s+1;
    int s2=e-mid;
    int a[s1],b[s2];
    for(int i=0;i<s1;i++){
        a[i]=p[s+i];    
    }
    for(int i=0;i<s2;i++){
        b[i]=p[mid+1+i];
    }
    int i=0,j=0;
    int k=s;
    while(i<s1&&j<s2){
        if(a[i]<=b[j]){
         p[k]=a[i];
         i++;
         k++;
        }
        if(a[i]>b[j]){
        p[k]=b[j];
        j++;
        k++;
        }
    }
    while(i<s1){
        p[k]=a[i];
        i++;
        k++;
    }
    while(j<s2){
        p[k]=b[j];
        j++;
        k++;
    }

}
void mergesort(int *p,int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        mergesort(p,s,mid);
        mergesort(p,mid+1,e);
        merge(p,s,mid,e);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}