#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int dp[n+1], i;
    dp[1] = 0;
    for(i=2;i<=n;i++)
    {
        dp[i] = 1 + dp[i-1];
        if(i%2==0)
        {
            if(dp[i]<(1+dp[i/2]))
                dp[i] = dp[i];
            else
                dp[i] = 1+ dp[i/2];
        }
        if(i%3==0)
        {
            if(dp[i]<(1+dp[i/3]))
                dp[i] = dp[i];
            else
                dp[i] = 1+ dp[i/3];
        }
    }
    printf("%d\n",dp[n]);
    return  0;
}
