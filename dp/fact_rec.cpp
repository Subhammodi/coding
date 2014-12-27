#include <stdio.h>
#include <iostream>

int fact(int value)
{
	int temp;

	if(value == 0 || value == 1)
		return 1;
	else
		return value*fact(value-1);
}

int main()
{
	int value;
	while(1)
	{
		scanf("%d", &value);
		printf("%d\n", fact(value));
	}
	return 0;
}