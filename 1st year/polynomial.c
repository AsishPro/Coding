#include<stdio.h>
#include<stdlib.h>

int addpoly();

struct polynomial{
int coeff;
int expo;
}poly,p1[10], p2[10],p3[100];


int main()
{
    int k;
  k=addpoly();
  for(int i=0;i<k;i++)
  {    
      printf("%d(x^%d)+",p3[i].coeff,p3[i].expo);
     // printf("%d(x^%d)+",p3[k-1].coeff,p3[k-1].expo);
  }
}

int addpoly()
{

     int t1,t2;
    printf("Enter the no of terms 1st polymonial\n");
    scanf("%d",&t1);
    printf("Enter the coefficients and the exponential values\n");
    
    for(int i=0; i<t1;i++)
    {
        printf("Enter the coefficients\n");
        scanf("%d",&p1[i].coeff);
        printf("Enter the exponential\n");
        scanf("%d",&p1[i].expo);
    }
    
    printf("Enter the no of terms for 2nd polymonial\n");
    scanf("%d",&t2);
      printf("Enter the coefficients and the exponential values\n");
    
    for(int j=0; j<t2;j++)
    {
        printf("Enter the coefficients\n");
        scanf("%d",&p2[j].coeff);
        printf("Enter the exponential\n");
        scanf("%d",&p2[j].expo);
    }
    //set
    int i=0,j=0,k=0;
    
    while(i<t1 && j<t2)
    {
    if(p1[i].expo==p2[j].expo)
    {
         p3[k].coeff=p1[i].coeff+p2[j].coeff;
          p3[k].expo=p1[i].expo;
          i++;
          j++;
          k++;
    }
    
    else if(p1[i].expo>p2[j].expo)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;
        k++;
    }
    
    
    else{
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
      j++;
      k++;
    }
      while(i<t1||j<t2)
   {
       if(i<t1){
    p3[k].coeff=p1[i].coeff;
     p3[k].expo=p1[i].expo;
      i++;
      k++;
       }
       else{
     p3[k].coeff=p2[j].coeff;
     p3[k].expo=p2[j].expo;
     j++;
     k++;
}
   }
return k;
}