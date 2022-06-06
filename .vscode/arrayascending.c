
#include <stdio.h>
int main(){
     int n1,n2;
     printf("ENter the Size of n1,n2: \n");
     scanf("%d%d",&n1,&n2);
    int arr1[n1],arr2[n2];
    printf("\nEnter Matrix 1:");
    for(int x=0;x<n1;x++){
    scanf("%d",&arr1[x]);
    }
    printf("\nEnter Matrix 2:");
    for(int x=0;x<n2;x++){
    scanf("%d",&arr2[x]);
    }
    
        int c[100];
  int k=0;
    for(int j=0;j<n2;j++){
    for(int i=0;i<n1;i++){
      if(arr1[i]==arr2[j]){
        c[k]=arr1[i];
        k++;
      }
    }
  }
    for(int x=0;x<k;x++){
    printf("%d ",c[x]);
    }
}