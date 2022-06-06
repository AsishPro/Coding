#include <stdio.h>
int graph[10][10],visited[10],n;
void bfs(int vertex){
    int x=0;
    printf("%d\t",vertex);
    visited[vertex]=1;
    for(x=0;x<n;x++){
            if(!visited[x] && graph[vertex][x]==1){
                bfs(x);
            }
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
    printf("BFS traversal is:\n");
    bfs(0);
}
