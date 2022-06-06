#include<stdio.h>
void TOH(int n,char A,char B,char C){

if(n>0){
TOH(n-1,A,C,B);
printf("\nMove from %c to %c",A,C);
TOH(n-1,B,A,C);
}

}
int main(){
int n;
printf("Enter the Number of rods:");
scanf("%d",&n);
TOH(n,'A','B','C');
}