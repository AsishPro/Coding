#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a,b,k,save;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        k=a;
        while(1){
        if(a%b==0){
         save=a;
         break;
        }
        else
        a++;
        }
      
       printf("%d\n",save-k);
    }
}