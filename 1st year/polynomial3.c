#include <stdio.h>
struct polynom{
    int coef;
    int exp;
};
struct polynom p1[10],p2[10],r[20];
int polyadd(struct polynom a[10],struct polynom b[10],int n1,int n2){
        int i=0,j=0,k=0;
        while(i<n1&&j<n2){
            if(a[i].exp==b[j].exp){
                r[k].exp=a[i].exp;
                r[k].coef=a[i].coef+b[i].coef;
                i++;
                j++;
                k++;
            }
            else if(a[i].exp>b[j].exp){
                 r[k].exp=a[i].exp;
                 r[k].coef=a[i].coef; 
                 i++;
                 k++;
            }
            else{
            r[k].exp=b[j].exp;
            r[k].coef=b[j].coef;
            k++;
            j++;
            }
        }
        while(i<n1){
            r[k].exp=a[i].exp;
            r[k].coef=a[i].coef;
            i++;
            k++;
        }
        while(j<n2){
            r[k].exp=b[j].exp;
            r[k].coef=b[j].coef;
            j++;
            k++;
        }
    return k; 
}
void insert(struct polynom p[10],int n){
 for(int i=0;i<n;i++){
    printf("Enter the Exponent of Term %d: ",i+1);
    scanf("%d",&p[i].exp);
    printf("Enter the Coefficient of Term %d: ",i+1);
    scanf("%d",&p[i].coef);
   }
}
int main(){
    int n1,n2,k;
   printf("Enter the Number of Terms in Polynomial 1: ");
   scanf("%d",&n1);
   insert(p1,n1);
   printf("Enter the Number of Terms in Polynominal 2: ");
   scanf("%d",&n2);
   insert(p2,n2);
   k=polyadd(p1,p2,n1,n2);
   for(int i=0;i<k-1;i++){
   printf("%d(x^%d)+",r[i].coef,r[i].exp);
   printf("%d(x^%d)",r[k-1].coef,r[k-1].exp);
   }
}