#include <stdio.h>
#include <iostream>
#include <string.h>

int lis(char *input)
{
	int answer = 0;
	int i, j;
	int *dp = new int[strlen(input)];
	for(i=0; i<strlen(input); i++)
        dp[i] = 1;

	for(i=0; i<strlen(input); i++)
	{
		for(j=0; j<i; j++)
			if(input[j] < input[i] && dp[i] < (1 + dp[j]))
				dp[i] = 1 + dp[j];
		if(answer < dp[i])
			answer = dp[i];
	}
	return answer;
}

int main()
{
	int size;
	while(1)
	{
		scanf("%d", &size);
		char *input = new char[size];
		scanf("%s", input);
		printf("Answer = %d.\n\n", lis(input));
	}
	return 0;
}
