#include<stdio.h>
int main()
{
    int n,ch,r,a[9],i=0,j,d;
    char c[8];
    scanf("%d%d",&n,&ch);
    d =n;
    if (ch == 0){
        for(i=0;i<9;i++)
        a[i] = 0;
        i =0;
        while(n){
            r =n%2;
            a[i] = r;
            n = n/2;
            i++;
        }
        if(d>=8) j =8;
        else j =4;
        for(i=j;i>=0;i--)
        printf("%d",a[i]);
    }
    else if (ch==1){
        i=0;
        while(n){
            r = n%16;
            if(r<10)
            c[i] = r+48;
            else 
            c[i] = r +55;
            n =n/16;
            i++;
        }
        for(j=i-1;j>=0;j--)
        printf("%c",c[j]);
    }
    return 0;
}