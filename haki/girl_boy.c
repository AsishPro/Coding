#include <stdio.h>
#include <string.h>
int main(){
    char ch[100];
    scanf("%s",ch);
    int a=strlen(ch);
    int count=0;
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            if(ch[i]!=ch[j]){ 
             continue;
            }
            else
            count++;
        }
      }
    a-=count;
    if(a%2==0){
    printf("CHAT WITH HER!");
    }
    else
    printf("IGNORE HIM!");
}