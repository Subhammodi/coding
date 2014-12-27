#include <stdio.h>
#include <iostream>

int *save = new int[10];
int fact(int value)
{
	if(value < 10 && save[value] != -1)
		return save[value];
	else if(value < 10)
	{
		save[value] = value*fact(value-1);
		return save[value];
	}
	else
		return value*fact(value-1);
}

int main()
{
	int value, i;
	while(1)
	{
		for(i=0; i<10; i++)
			save[i] = -1;
		save[0] = 1;
		save[1] = 1;
		scanf("%d", &value);
		printf("%d\n", fact(value));
	}
	return 0;
}
