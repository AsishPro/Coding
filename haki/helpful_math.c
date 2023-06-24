#include <stdio.h>
#include <string.h>
int main(){
    char a[101];
    scanf("%s",a);
    int k=strlen(a);
    char temp;
    for(int i=0;i<k-2;i=i+2){
        for(int j=i+2;j<k;j=j+2){
              if(a[i]>a[j]){
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
            }
        }
    }
    printf("%s",a);
}