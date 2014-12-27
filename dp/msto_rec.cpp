#include<stdio.h>

int msto(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 0;
	else
	{
		int min;
		min = 1 + msto(n-1);
		if(n%2 == 0)
		{
			if(min > (1+msto(n/2)))
				min = 1 + msto(n/2);
		}
		if(n%3 == 0)
		{
			if(min > (1 + msto(n/3)))
				min = 1 + msto(n/3);
		}
		return min;
	}
}
int main()
{
    int n, i;
    while(1)
    {
    	scanf("%d",&n);
    	printf("%d\n",msto(n));
    }
}