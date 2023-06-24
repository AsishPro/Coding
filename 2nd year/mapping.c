#include <stdio.h>
#include <String.h>
int main(){
    int a[26]={0};
    char s[10];
    printf("Enter the string: ");
    scanf("%s",s);
    int k=strlen(s);
    // printf("%d",a[s[0]-'a']);
     for(int i=0;i<k;i++){
        a[s[i]-'a']++;
     }
     for(int i=0;i<26;i++){
        printf("%c-%d\n",i+97,a[i]);
        //x++;
     }
     int max=a[0];
     //printf("%d\n",max);
     for(int i=0;i<26;i++){
          if(a[i]>max){
           max=i;            
         }
      }
    printf("\nMaximum element is %c",max+97);
}