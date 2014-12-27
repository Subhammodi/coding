#include <stdio.h>
#include <iostream>

void coin_dp(int **result, int k, int l)
{
	int i, j;

	for(i=1; i<=1000000; i++)
	{
		for(j=0; j<2; j++)
		{
			if(i == 1 || k == i || l == i)
				result[i-1][j] = j;
			else if(k < i && l < i)
			{
				if(result[i-k-1][(j+1)%2] == j || result[i-l-1][(j+1)%2] == j || result[i-2][(j+1)%2] == j)
					result[i-1][j] = j;
				else
					result[i-1][j] = (j+1)%2;
			}
			else if(l < i)
			{
				if(result[i-l-1][(j+1)%2] == j || result[i-2][(j+1)%2] == j)
					result[i-1][j] = j;
				else
					result[i-1][j] = (j+1)%2;
			}
			else if(k < i)
			{
				if(result[i-k-1][(j+1)%2] == j || result[i-2][(j+1)%2] == j)
					result[i-1][j] = j;
				else
					result[i-1][j] = (j+1)%2;
			}
			else
			{
				if(result[i-2][(j+1)%2] == j)
					result[i-1][j] = j;
				else
					result[i-1][j] = (j+1)%2;
			}
		}
	}
}

int main()
{
	int k, l, cases;
	int i, j;
	scanf("%d%d%d", &k, &l, &cases);
	int *coins = new int[cases];
	int **result = new int *[1000000];
	for(i=0; i<1000000; i++)
		result[i] = new int[2];
    coin_dp(result, k, l);
    for(i=0; i<cases; i++)
        scanf("%d", &coins[i]);

	for(i=0; i<cases; i++)
	{
		if(result[coins[i] - 1][0] == 0)
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
}
