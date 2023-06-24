#include <stdio.h>
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
int main(){
  int size;
  printf("Enter the size of the array::\n");
  scanf("%d",&size);
    int a[size];
    for(int i=0;i<size;i++){
    scanf("%d",&a[i]);
   }
  int n=size;
  while(n--){
    printf("%d \n",n);
  for(int j=0;j<n;j++){
      if(a[j]>a[j+1]){
          swap(&a[j],&a[j+1]);
      }
    }
  }
 
  for(int i=0;i<size;i++){
    printf("%d ",a[i]);
   }
    

}