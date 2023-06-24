#include <stdio.h>
#include <string.h>
int main(){
    int n;
   scanf("%d",&n);
    int x=0;
    char s[4];
   for(int i=0;i<n;i++){
       scanf("%s",s);
       //printf("%s",s);
       //int k=strlen(s);
      // printf("\n%d",k);
       if(s[1]=='+')
       x++;
       else
       x--;
    }
    printf("%d",x);
    //
}