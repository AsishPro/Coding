#include<stdio.h>
int main()
{
    int i,j,k;
    int cal=0,max=0;
    int size,index=0;
    scanf("%d",&size);
    int a[size];
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
    for(i=0;i<size;i++)
    {
        cal=0;
        for(j=i+1;j<size;j++)
        {
            if(a[i]==a[j])
            cal++;
        }
        if(cal>max)
        {
            max=cal;
            index=i;
        }
    }
    printf("%d",a[index]);
}