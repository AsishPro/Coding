#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[101];
    scanf("%s",s);
    int count1=0,count2=0,k=strlen(s);
    for(int i=0;i<k;i++){
        if(s[i]>=97)
        count1++;
        else
        count2++;
    }
    int j=0;
    //printf("%d %d\n",count1,count2);
    if(count1>=count2){
        while(s[j]){
         printf("%c",tolower(s[j]));
            j++;
        }
    }
    else{
         while(s[j]){
            printf("%c",toupper(s[j]));
            j++;
        }
    }  
}