#include <stdio.h>
#include <stdlib.h>
int graph[10][10],visited[10],n,a[40];
static int k=0,count=0;
void dfs(int vertex){
    int c=0,x=0;  
    count++;
    printf("%d\t",vertex);
    visited[vertex]=1;
    for(x=0;x<n;x++){
            if(!visited[x] && graph[vertex][x]==1){  
                a[++k]=x;
                c=1;
            }
            if(count==n){
                exit(0);
            }
        }
    if(c==1){
        dfs(a[k]);
    }
    else {
        k--;
        dfs(a[k]);
    }
}
int main(){
    printf("\nEnter the number of vertices in graph: ");
    scanf("%d",&n);
    printf("\nEnter the Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
        visited[i]=0;
    }
    printf("DFS traversal is:\n");
    dfs(0);
}
