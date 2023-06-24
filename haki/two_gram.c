#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    int count=0,max=0,ch[2];
    for(int i=0;i<n-1;i++){
       for(int j=i+2;j<n;j++){
        count=0;
        if(s[i]==s[j]&&s[i+1]==s[j+1]){
            count++;
            if(count>max){
            ch[0]=s[i];
            ch[1]=s[i+1];
            max=count;
            } 
        }
      }
    }
    printf("%s",ch);
}