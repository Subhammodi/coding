#include<stdio.h>

int *memo = new int[10000];
int coins(int n)
{
    if(n < 10000 && memo[n] != -1)
        return memo[n];
    else if(n < 10000)
    {
        if(n > (n/2 + n/3 + n/4))
            memo[n] = n;
        else
            memo[n] = coins(n/2) + coins(n/3) + coins(n/4);
        return memo[n];
    }
    else
    {
        if(n > (n/2 + n/3 + n/4))
            return n;
        else
            return (coins(n/2) + coins(n/3) + coins(n/4));
    }
}
int main()
{
    int n, i;
    while(1)
    {
    	scanf("%d",&n);
        for(i=0; i<10000; i++)
            memo[i] = -1;
        memo[0] = 0;
        memo[1] = 1;
    	printf("%d\n",coins(n));
    }
}
