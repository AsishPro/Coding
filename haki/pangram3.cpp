#//include <stdio.h>
#include <iostream>
//#include <ctype.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int mark,r[26]={0},k;
    char s[n];
    scanf("%s",s);
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(isupper(s[i])){
           r[s[i]-'A']++;
        }
        else{
            r[s[i]-'a']++;          
        }
    }
    int flag=0;
    for(int i=0;i<26;i++){
        if(r[i]==0)
         flag=1;       
    }
    if(flag==0)
    printf("YES");
    else
    printf("NO");
}