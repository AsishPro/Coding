#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mod(char a,char b){
    if(a>b)
        return a-b;
    else
        return b-a;
}
int main(){
    char a[101],b[101];
    scanf("%s%s",a,b);
    int k=strlen(a);
    int x,z,count=0;
    for(int i=0;i<k;i++){ 

            if(toupper(a[i])>toupper(b[i]))
            z=z+mod(toupper(a[i]),toupper(b[i]));
            else if(toupper(a[i])<toupper(b[i]))
            x=x+mod(toupper(a[i]),toupper(b[i]));
            else
            count++;    
    }
    if(count==k)
    printf("0");
    else if(z>x)
    printf("1");
    else 
    printf("-1");
    }