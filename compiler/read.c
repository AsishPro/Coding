#include <stdio.h>
int main(){
    FILE *fp;
    fp=fopen("INPUT.txt","w");
    char c;
    while((c=getchar())!=EOF){
        putc(c,fp);
    }
}
