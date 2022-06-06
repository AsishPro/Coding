#include <stdio.h>
#include <string.h>
int main(){
    char a[50],b[50];
    scanf("%[\n]s",a);
    int l=strlen(a);
    int k=0;
    for(int i=0;i<l;i++){
      b[i]=a[l-1];
      --l;
    }
    if(strcmp(a,b)==1){
        printf("YES");
    }
    else
    printf("NO");
}