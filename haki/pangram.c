#include<stdio.h>
 
int main() {
    int p=0,cap=0,smal=0,n;

    scanf("%d",&n);
     char ch[n];
     int a[n]={0};
     scanf("%s",ch);
   for(int i=0;i<n;i++){
   if (ch[i] >= 'A' && ch[i] <= 'Z')
       cap++;
   else
      for(int i=0;i<n;i++){
        a[ch[i]-'a']++;
        if(a[ch[i]-'a']>0)
        {
          
        }
     }
      smal++;
     if(ch[i]>='a'&&ch[i]<='z')
      
   }
   printf("%s\n",ch);
   if(cap!=0&&smal!=0)
   printf("YES");
   else{
   printf("NO");
   return (0);
   }
}