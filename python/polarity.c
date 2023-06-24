#include <stdio.h>
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void polarity(int *p,int n){
    int j = 0;
    int k[n];
    for (int i = 0; i < n; i++) {
        if (p[i] >= 0) {
            k[j]=p[i];
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] < 0) {
            k[j]=p[i];
            j++;
        }
    }
    for (int i = 0; i <n; i++)
        printf("%d ",k[i]);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("old is:");
    for (int i = 0; i <n; i++)
        printf("%d ",a[i]);
    printf("\nnew is:\n");
    polarity(a,n);

}