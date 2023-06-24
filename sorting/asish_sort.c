#include <stdio.h>
int main(){
    int k=0,n;
    scanf("%d",&n);
    int a[n],s[n];
    for(int i=0;i<n;i++){
        scanf("%d",a[i]);
        if(i==1){
        s[k]=a[i];
        k++;
        }
        else if(a[i]>s[k-1]){
        k++;
        s[k]=a[i];
        }
        else if(a[i]<s[k-1]){
            
        }
   

    }
}


