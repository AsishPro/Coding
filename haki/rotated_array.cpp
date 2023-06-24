#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    int s=0,e=n-1;
    int index;
    while(s<=e){
       int mid=(s+e)/2;
       if(a[mid]==target){
          index=mid;
          break;
       }
       else if(a[mid]>target)
         s=mid+1;
       else
         e=mid-1;
    }
   

    //finding max element right side
    int max=a[index+1];
    for(int i=index;i<n;i++){
        if(a[i]>max)
          max=a[i];
    }

    //finding min element left side
    int min=a[index-1];
     for(int i=index;i>=0;i--){
        if(a[i]<min)
          min=a[i];
      }
    
    
    cout<<"Maximum is "<<max<<endl;
    cout<<"Minimum is "<<min<<endl;
}