
#include <stdio.h>
void f3(int *A) {
   int i, j;
   //i implies one row elements 
   for(i = 0 ; i < 3 ; i++) {
      printf("\n"); 
      for(j = 0 ; j < 3 ; j++)
        printf("%2d ", *(A+ 3*i + j));
    }

 printf("\n");
} 
int main() { 
    int A[3][3],i,j;
    for(i = 0 ; i < 3 ; i++) 
      for(j = 0 ; j < 3 ; j++) 
         A[i][j] = i*10 + j;

    printf("Initialized data to: \n"); 
    for(i = 0 ; i < 3 ; i++) { 
         for(j = 0 ; j < 3 ; j++) 
           printf("%2d ", A[i][j]);
        printf("\n");
     }  

     f3(*A);

   return 0;
 } 
