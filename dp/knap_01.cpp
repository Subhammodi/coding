#include <stdio.h>
#include <iostream>

int knap(int limit, int *weight, int *value, int n)
{
	int i, j, temp;
	int **max = new int *[limit+1];
	for(i=0; i<=limit; i++)
	{
		max[i] = new int[n+1];
		for(j=0; j<=n; j++)
			max[i][j] = 0;
	}

	for(i=1; i<=limit; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(weight[j-1] <= i)
			{
				if((max[i - weight[j-1]][j-1] + value[j-1]) > max[i][j-1])
					max[i][j] = max[i - weight[j-1]][j-1] + value[j-1];
				else
					max[i][j] = max[i][j-1];
			}
			else
				max[i][j] = max[i][j-1];
		}
	}
	return max[limit][n];
}

int main()
{
	int i, n, limit;
	while(1)
	{
		scanf("%d", &limit);
		scanf("%d", &n);
		int *weight = new int[n];
		int *value = new int[n];
		for(i=0; i<n; i++)
		{
			scanf("%d", &weight[i]);
			scanf("%d", &value[i]);
		}
		printf("\nValue = %d\n\n", knap(limit, weight, value, n));
	}
	return 0;
}
