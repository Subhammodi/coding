#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int n, i, j, k, p, q;
	int min;

	while(scanf("%d",&n) > 0)
	{
		int col[n];
		int mix[n][n];
		int smo[n][n];

		memset(mix, 0, n*sizeof(int));
		memset(smo, 0, sizeof(smo));

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

        /*printf("%d\t",&col[0]);
        printf("%d\n",col);
        printf("%d\t",&col[1]);
        printf("%d\n",col+1);
        printf("%d\t",col[1]);
        printf("%d\n",*(col+1));
        printf("%d\t",*(mix[1]+1));
        printf("%d\t",mix[1][1]);
        printf("%d\n",**(mix + (n-1)*1 + 1));
        printf("%d\t",mix[1]+1);
        printf("%d\t",(mix + 1+1));
        printf("%d\t",(&mix[1][2]));
        printf("%d\t",(&mix[2][0]));
        printf("\n");*/
        //printf("%d\t",*(mix);
        //printf("%d\n",*(col+1));

		for(i = 1; i <= (n-1); i++)
		{
			for(j = 0; j <= (n-1-i); j++)
			{
				p = i + j;
				min = 9999999;
				for(k = j+1; k <= p; k++)
				{
					if(smo[j][k-1] + smo[k][p] + mix[j][k-1]*mix[k][p] < min)
						min = smo[j][k-1] + smo[k][p] + mix[j][k-1]*mix[k][p];
				}
				smo[j][p] = min;
			}
		}
		printf("%d\n",smo[0][n-1]);
	}
	return 0;
}
