#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct s{
    char c[10000];
};
int main(){
     
    int n;
    scanf("%d",&n);
    struct s *p=(struct s *)malloc(n*sizeof(struct s));

 
    for(int i=0;i<n;i++){
        scanf("%s",(p+i)->c);
    }
        int k;
//
    for(int i=0;i<n;i++){
           k=strlen((p+i)->c);
           if(k>10)
        printf("%c%d%c\n",(p+i)->c[0],k-2,(p+i)->c[k-1]);
        else 
        printf("%s\n",(p+i)->c);
    }
    
    // printf("\n");
    // for(int i=0;i<n;i++){
    //     printf("%s\n",(p+i)->c);
    // }
}