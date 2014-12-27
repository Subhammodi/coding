#include<stdio.h>

int coins(int n)
{
	if(n >= (n/2 + n/3 + n/4))
		return n;
	else
		return (coins(n/2) + coins(n/3) + coins(n/4));
}
int main()
{
    int n, i;
    while(1)
    {
    	scanf("%d",&n);
    	printf("%d\n",coins(n));
    }
}