#include <stdio.h>
#include <iostream>

int matrix(int **arr, int n)
{
	int i, j, k, temp, curr;
	int **C = new int *[n];
	for(i=0; i<n; i++)
	{
		C[i] = new int[n];
		for(j=0; j<n; j++)
			if(i == j)
				C[i][j] = 0;
			else
				C[i][j] = 999999999;
	}

	for(i=1; i<=(n-1); i++)
	{
		for(j=0; j<(n-i); j++)
		{
			temp = j+i;
			curr = C[j][temp];
			for(k=j; k<temp; k++)
			{
				if(curr > (C[j][k] + C[k+1][temp] + arr[j][0]*arr[k][1]*arr[temp][1]))
					curr = C[j][k] + C[k+1][temp] + arr[j][0]*arr[k][1]*arr[temp][1];
			}
			C[j][temp] = curr;
		}
	}

	return C[0][n-1];
}

int main()
{
	int n, i, j;
	while(1)
	{
		scanf("%d", &n);
		int **arr = new int *[n];
		for(i=0; i<n; i++)
		{
			arr[i] = new int[2];
			scanf("%d%d", &arr[i][0], &arr[i][1]);
		}
		printf("Value = %d.\n\n", matrix(arr, n));
	}
	return 0;
}