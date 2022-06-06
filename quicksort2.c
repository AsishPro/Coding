#include <stdio.h>
void quicksort(int a[],int start,int end){
   int i, j, pivot, temp;
   if(start<end){
      pivot=start;
      i=start;
      j=end;
      while(i<j){
         while(a[i]<=a[pivot]&&i<end)
         i++;
         while(a[j]>a[pivot])
         j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      
      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,start,j-1);
      quicksort(a,j+1,end);
   }
}
int main(){
   int n;
   printf("Enter the Number of Elements:");
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++){
   printf("Enter %d elements: ", i+1);
   scanf("%d",&a[i]);
   }
   quicksort(a,0,n-1);
   printf("Increasing Sorted Order: ");
   for(int i=0;i<n;i++){
   printf(" %d",a[i]);
   }
}