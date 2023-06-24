#include<stdio.h>
void print(int *mat, int i, int j, int m, int n,int *path,int pi)
{
	if (i == m - 1)
	{
		for (int k = j; k < n; k++)
			path[pi + k - j] = *((mat + i*n) + k);
		for (int l = 0; l < pi + n - j; l++)
			printf("%d ",path[l]);
		printf("\n");
		return;
	}
	if (j == n - 1)
	{
		for (int k = i; k < m; k++)
			path[pi + k - i] = *((mat + k*n) + j);
		for (int l = 0; l < pi + m - i; l++)
			printf("%d ",path[l]);
		printf("\n");
		return;
	}
	path[pi] = *((mat + i*n) + j);
	print(mat, i+1, j, m, n, path,pi + 1);
	print(mat, i, j+1, m, n, path, pi + 1);
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

	int matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
         scanf("%d",&matrix[i][j]);
    }
    printf("paths are: \n");
    int path[m+n];
	print(*matrix, 0, 0, m, n,path,0);
	return 0;
}