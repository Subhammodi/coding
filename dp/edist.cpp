#include <stdio.h>
#include <iostream>
#include <string.h>

char str1[2001];
char str2[2001];
int result[2001][2001];

int minimum(int a, int b, int c)
{
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;
}

int edist()
{
	int i, j;

	for(i=1; i<=strlen(str1); i++)
	{
		for(j=1; j<=strlen(str2); j++)
		{
			if(str1[i-1] == str2[j-1])
				result[i][j] = minimum(1 + result[i-1][j], 1 + result[i][j-1], result[i-1][j-1]);
			else
				result[i][j] = minimum(1 + result[i-1][j], 1 + result[i][j-1], 1 + result[i-1][j-1]);
		}
	}

	return result[strlen(str1)][strlen(str2)];
}

int main()
{
	int i, j, cases;
	scanf("%d", &cases);
	for(i=0; i<=2000; i++)
		result[i][0] = i;
	for(i=0; i<=2000; i++)
		result[0][i] = i;
	for(i=0; i<cases; i++)
	{
		scanf("%s%s", str1, str2);
		printf("%d\n", edist());
	}
	return 0;
}
