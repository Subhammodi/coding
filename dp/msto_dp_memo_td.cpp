#include<stdio.h>

int msto(int n, int *memo)
{
    if(memo[n] != -1)
        return memo[n];
    else
    {
        memo[n] = 1 + msto(n-1, memo);
        if(n%2 == 0)
        {
            if(memo[n] > (1+msto(n/2, memo)))
                memo[n] = 1 + msto(n/2, memo);
        }
        if(n%3 == 0)
        {
            if(memo[n] > (1 + msto(n/3, memo)))
                memo[n] = 1 + msto(n/3, memo);
        }
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
        memo[1] = 0;
	    printf("%d\n",msto(n, memo));
    }
}
