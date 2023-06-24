#include <stdio.h>
#include <string.h>
int alp[26]={0};
void count(int k,char *p){
  for(int i=0;i<k;i++){
    alp[*(p+i)-'A']++;
     }
}
int main(){
    char a[100],b[100],c[100];
     scanf("%s%s%s",a,b,c);
     int k=strlen(a),u=strlen(b),x=strlen(c);
     count(k,a);
     count(u,b);
     int d[26]={0};
    for(int i=0;i<x;i++){
        d[c[i]-'A']++;
    }  
    k=0; 
    for(int i=0;i<26;i++){
        if(alp[i]!=d[i])
           k++;       
    }
    if(k==0)
    printf("YES");
    else
    printf("NO");            
}