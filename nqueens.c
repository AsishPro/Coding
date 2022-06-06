#include <stdio.h>
int a[30][30];
int checksquare(int x,int y,int n){
    for(int row=0;row<x;row++){
        if(a[row][y]==1){
            return 0;
        }
    }
     int row=x;
     int col=y;
    while(row>=0&& col>=0){
        if(a[row][col]==1){
            return 0;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0&&col<n){
        if(a[row][col]==1){
            return 0;
        }
        row--;
        col++;
    }
     return 1;
}

int Queen(int x,int n){
    if(x>=n){
        return 1;
    }
    for(int col=0;col<n;col++){ 
           if(checksquare(x,col,n)){
               a[x][col]=1;
               if(Queen(x+1,n)){
                   return 1;
               }
               a[x][col]=0; //backtrack
           }     
    }
    return 0;
}

int main(){
     
     int n;
     printf("Enter the number of Order of Chess Board(n):");
     scanf("%d",&n);
    
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             a[i][j]=0;
         }
     }
     if(Queen(0,n)){
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 printf("%d ",a[i][j]);
             }
             printf("\n");
         }
     }

}