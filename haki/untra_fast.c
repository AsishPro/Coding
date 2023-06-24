#include <stdio.h>
#include <string.h>
int main(){
    char a[101],b[101];
    scanf("%s%s",a,b);
    
    int k=strlen(a);
    int r[k];
    for(int i=0;i<k;i++){
      if(a[i]!=b[i])
       r[i]=1;
      else
       r[i]=0;
    }
    for(int i=0;i<k;i++){
        printf("%d",r[i]);
    }
}