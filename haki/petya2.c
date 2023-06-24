#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char a[101],b[101];
    scanf("%s%s",a,b);
    int k=strlen(a),count=0;
    for(int i=0;i<k;i++){ 

            if(toupper(a[i])>toupper(b[i])){
            printf("1");
            break;
            }
            else if(toupper(a[i])<toupper(b[i])){
            printf("-1");
            break;
            }
            else
            count++;    
    }
    if(count==k)
    printf("0");
    }