#include <stdio.h>
#include <iostream>

int lcs(char *input1, char *input2, int s1, int s2)
{
	int answer = 0;
	int i, j, k, l, max;
	int **dp = new int *[s1];

	for(i=0; i<s1; i++)
	{
		dp[i] = new int[s2];
		for(j=0; j<s2; j++)
			dp[i][j] = 0;
	}

	for(i=0; i<s1; i++)
	{
		for(j=0; j<s2; j++)
		{
			if(input1[i] == input2[j])
			{
				max = 0;
				for(k=0; k<i; k++)
					for(l=0; l<j; l++)
						if(max < dp[k][l])
							max = dp[k][l];

				dp[i][j] = 1 + max;
			}
			else
				continue;
		}
	}

	max = 0;
	for(i=0; i<s1; i++)
	{
		for(j=0; j<s2; j++)
		{
			if(max < dp[i][j])
            {
				max = dp[i][j];
				k = i;
				l = j;
            }
		}
	}
	printf("K = %d\tL = %d\n", k, l);
	return max;
}

int main()
{
	int size1, size2;
	while(1)
	{
		scanf("%d%d", &size1, &size2);
		char *input1 = new char[size1];
		char *input2 = new char[size2];
		scanf("%s", input1);
		scanf("%s", input2);
		printf("Answer = %d.\n\n", lcs(input1, input2, size1, size2));
	}
	return 0;
}
