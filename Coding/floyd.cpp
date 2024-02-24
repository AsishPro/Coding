#include<stdio.h>
//#define INF 999
void floydwarshall(int G[100][100],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(G[i][k] + G[k][j] < G[i][j]){
                    G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==9999){
                printf("INFI,");
            }
            else{
                printf("%d,  ",dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int G[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    floydwarshall(G,n);
}