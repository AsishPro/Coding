#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct s{
    char c[100];
};
int main(){
      
    int n;
    scanf("%d",&n);
    struct s *p=(struct s *)malloc(n*sizeof(struct s));
    for(int i=0;i<n;i++){
        scanf("%s",&(p+i)->c);
    }

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s\n",(*(p+i)).c);
    }
}