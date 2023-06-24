#include <stdio.h>
int main(){
    int a[5][5];
    int x,y;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1){
                x=i,y=j;
            }
        }
    }
    int count=0;
     while(1){
     if(y>2){
     y--;
     count++;
     }
     else if(y<2){
     y++;
     count++;
     }
     else
     break;
     }

      while(1){
     if(x>2){
     x--;
     count++;
     }
     else if(x<2){
     x++;
     count++;
     }
     else
     break;
     }
     printf("%d",count);
   
    
    
}