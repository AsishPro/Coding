#include <stdio.h>
#include <string.h>
int main(){
    char a[101],b[101];
    scanf("%s%s",a,b);
    int k=strlen(a),flag=0;
    for(int i=0;i<k;i++){
       if(a[i]!=b[k-i-1])
          flag=1;
    }
    if(flag==1)
    printf("NO");
    else
    printf("YES"); 

}