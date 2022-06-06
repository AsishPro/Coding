#include <stdio.h>
int static c=1;
int quicksort(int pivot,int p[],int n){
    int i=0,k=n;
    if(c%2==0){
        while(i<k){
            if(p[n]<p[i]){
                int temp=p[n];
                p[n]=p[i];
                p[i]=temp;
                c++;
                return quicksort(i,p,n);
            }
            i++;
        }
    }
    else if(p[pivot]>p[n]){
   for(int i=n;i>=0;i--){
        if(p[pivot]>p[n]){
            int temp=p[n];
             p[n]=p[pivot];
             p[pivot]=temp;
             return quicksort(pivot,p,n);   
              c++;
        }
    }
    }
    else 
    return p;
}
int main(){
    int n;
    printf("Enter the Number of ELements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   int *k=quicksort(0,a,n-1);
   for(int i=0;i<n;i++){
       printf("%d ",*(k+i));
   }
}
