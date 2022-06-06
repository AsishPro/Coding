#include <stdio.h>
void TOH(int n,char A,char B, char C){
   if(n>1){
    TOH(n-1,A,C,B);
    printf("%c to %c",A,C);
    TOH(n-1,);
    printf("\n%c to %c",C,B);
}
}
int main(){
    int n;
    printf("Enter the Numbe of Rods");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}