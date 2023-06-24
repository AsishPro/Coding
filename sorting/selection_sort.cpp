#include <iostream>
using namespace std;
void swap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}
void selection_sort(int *p,int n){
  
      for(int i=0;i<n-1;i++){
        int min=i;
         for(int j=i+1;j<n;j++){
           if(p[j]<p[min])
           min=j;
         }
      if(min!=i)
       swap(p[min],p[i]);
    }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}