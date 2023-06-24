#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    for(int i=0;i<n;i++){
        a[i]=a[i]*a[i];
    }
    int i=0;
    while(i<n){
    printf("%d ",a[i]);
    i++;
    }
    return 0;
}