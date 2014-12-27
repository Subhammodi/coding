#include<stdio.h>

int coins(int n, int *memo)
{
    int i;

    for(i=2; i<=n; i++)
    {
        if(i > (i/2 + i/3 + i/4))
            memo[i] = i;
        else
            memo[i] = memo[i/2]+ memo[i/3] + memo[i/4];
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
        for(i=0; i<n+1; i++)
            memo[i] = -1;
        memo[0] = 0;
        memo[1] = 1;
    	printf("%d\n",coins(n, memo));
    }
}
