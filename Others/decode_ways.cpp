#include<stdio.h>
#include<string>

using namespace std;

int dfs(string s ,int cur, int dp[]){
    if(cur == s.size())
        return 1;
    if(dp[cur+1] != -1)
        return dp[cur+1];
    if(s[cur] == '0')
    {
        dp[cur+1] = 0;
        return 0;
    }
    int total = 0, num = 0;

    int loop=2;
    if(s.size() - cur < 2)
        loop = s.size() - cur;
    dp[cur+1] = 0;
    //printf("%d\n\n", dp[cur+1]);
    for(int i=0; i<loop; i++)
    {
        num = num*10+(int)(s[cur+i]-'0');
        //printf("%d\n\n", dp[cur+1]);
        if(num <=26)
            dp[cur+1] += dfs(s, cur+i+1, dp);
        //printf("%d\n\n%d\n\n", dp[cur+1], num);
    }
    //printf("%d\n\n", dp[cur+1]);
    return dp[cur+1];
}

int numDecodings(string s) {
    if(s.size() == 0 || s[0] == '0')
        return 0;
    int dp[s.size()+1];
    for(int i=0; i<=s.size(); i++)
        dp[i] = -1;
    dp[0] = 0;
    return dfs(s, 0, dp);
}

int main()
{
    string input = "2711";
    printf("%d\n", numDecodings(input));
    return 0;
}
