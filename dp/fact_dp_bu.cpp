#include <stdio.h>
#include <iostream>

int main()
{
	int value, i, answer;
	while(1)
	{
		answer =1;
		scanf("%d", &value);
		for(i=1; i<=value; i++)
			answer = answer*i;
		printf("%d\n", answer);
	}
	return 0;
}
