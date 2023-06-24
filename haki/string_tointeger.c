#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[10];
    char a[2];
    scanf("%s",s);
    if(s[8]=='P'){
        if(s[0]=='1'&&s[1]=='2'){
        s[8]='\0';
        s[9]='\0';
        printf("%s",s);
        return 0;
        }
        else{ 
            char k[2];
            k[0]=s[0],k[1]=s[1];
            int val = atoi(k);
            // printf("Val=%d",val);
           sprintf(a,"%d",(val+12));
            //itoa(b+12,a,10);
           s[0]=a[0];
           s[1]=a[1];
           s[8]='\0';
           s[9]='\0';
           printf("%s",s);
           return 0;
        }
    }
    else{
        if(s[0]=='1'&&s[1]=='2'){
          s[0]='0',s[1]='0';
         s[8]='\0';
         s[9]='\0';
        printf("%s",s);
        return 0;
      }
      else{
         s[8]='\0';
        s[9]='\0';
        printf("%s",s);
      }
    }
   
    }
    