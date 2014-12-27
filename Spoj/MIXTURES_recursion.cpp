#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int smoke(int col[], int **mix, int **smo, int a, int b)
{
	int i, j, k, p;
	int min;

	if(a == b)
		return smo[a][b];
	else if( (b-a) == 1)
		return (mix[a][a]*mix[b][b]);
	else
	{
		min = 9999999;
		for(k = a+1; k <= b; k++)
		{
			if(smoke(col, mix, smo, a, k-1) + smoke(col, mix, smo, k, b) + mix[a][k-1]*mix[k][b] < min)
				min = smoke(col, mix, smo, a, k-1) + smoke(col, mix, smo, k, b) + mix[a][k-1]*mix[k][b];
		}
		return (smo[a][b] = min);
	}
}

int main()
{
	int n, i, j, k, p;

	while(scanf("%d",&n) > 0)
	{
		int col[n];
		int **mix = new int *[n];
		int **smo = new int *[n];

		for(i = 0; i <= (n-1); i++)
        {
            smo[i] = new int[n];
            mix[i] = new int[n];
        }

        for(i = 0; i <= (n-1); i++)
		{
			for(j = 0; j <= (n-1); j++)
			{
				mix[i][j] = 0;
				smo[i][j] = 0;
			}
		}

		for(i=0;i<n;i++)
		{
			scanf("%d",&col[i]);
			mix[i][i] = col[i];
		}

		int sum = 0;

		for(i = 0; i <= (n-1); i++)
		{
			sum = col[i];
			for(j = i+1; j <= (n-1); j++)
			{
				sum += col[j];
				mix[i][j] = sum%100;
			}
		}

		printf("%d\n",smoke(col, mix, smo, 0, n-1));
	}
	return 0;
}
