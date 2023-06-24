#include <stdio.h>

int triangularSum(int* nums, int numsSize){
   if(numsSize==1){

   return *(nums);
   }
    for(int i=0;i<numsSize;i++){
      *(nums+i)=(*(nums+i)+*(nums+i+1)) % 10;
   }
    triangularSum(nums,numsSize-1);
}


int main(){
    int a[5];
    for(int i=0;i<5;i++){
     scanf("%d",&a[i]);
    }
   
   printf("T_sum = %d",triangularSum(a,5));
}

