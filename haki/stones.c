#include <stdio.h>
int main(){
    int count=0,n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])
        count++;
    }
    printf("%d",count);
}