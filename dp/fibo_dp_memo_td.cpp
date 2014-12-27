#include<stdio.h>

int fibo(int n, int *memo)
{
	if(memo[n] != -1)
		return memo[n];
	else
	{
		memo[n] = fibo(n-1, memo) + fibo(n-2, memo);
		return memo[n];
	}
}

int main()
{
    int n, i;
    while(1)
    {
	    scanf("%d",&n);
	    int *memo = new int[n+1];
	    for(i=0; i<=n; i++)
	    	memo[i] = -1;
	    memo[0] = 0;
	    memo[1] = 1;
	    printf("%d\n",fibo(n, memo));
	}
}
