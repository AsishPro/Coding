#include <stdio.h>
#include <string.h>
void sort(int ch[]){
  int x=0;
  //printf("%s\n",ch);
  char a[101];
  int k=strlen(ch);
  for(int i=0;i<k-1;i++){
      if(ch[i]<ch[i+1]){
         a[x]=ch[i];
         x++;
       }
     }
  printf("%s",a);
  
}
int main(){
    int k;
    char ch[101];
    scanf("%s",ch);
    sort(ch);
    //return;
   }
