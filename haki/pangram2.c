#include <stdio.h>
#include <ctype.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n]={0};
    char s[n];
    scanf("%s",s);
    int count=0;
    for(int i=0;i<n;i++){
        if(isupr(s[i]))
         count++;
        else{
        a[s[i]-'a']++;
      if(a[s[i]-'a']>0)
         count++;
        }
    }
    if(count==26)
    printf("YES");
    else
    printf("NO");
}