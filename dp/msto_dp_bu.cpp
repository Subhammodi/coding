#include<stdio.h>

int msto(int n, int *memo)
{
	memo[0] = 0;
    memo[1] = 0;
    int i;

    for(i=2; i<=n; i++)
    {
        memo[i] = 1 + memo[i-1];
        if(i%2 == 0 && (memo[i] > (1+memo[i/2])))
                memo[i] = 1 + memo[i/2];
        if(i%3 == 0 && (memo[i] > (1 + memo[i/3])))
                memo[i] = 1 + memo[i/3];
    }
    return memo[n];
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
	    printf("%d\n",msto(n, memo));
    }
}
