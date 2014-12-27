#include<stdio.h>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    bool dp[s1.size()+1][s2.size()+1][s3.size()+1];
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            dp[i][j][0] = false;
        }
    }
    dp[0][0][0] = true;

    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            for(int k=1; k<=s3.size(); k++)
            {
                if(i==0 && j==0)
                    dp[i][j][k] = true;
                else if(i+j > k)
                    dp[i][j][k] = false;
                else if(i==0)
                {
                    if(dp[i][j][k-1] == true)
                        dp[i][j][k] = true;
                    else if(dp[i][j-1][k-1] == true && s3[k-1] == s2[j-1])
                            dp[i][j][k] = true;
                    else
                        dp[i][j][k] = false;
                }
                else if (j==0)
                {
                    if(dp[i][j][k-1] == true)
                        dp[i][j][k] = true;
                    else if(dp[i-1][j][k-1] == true && s3[k-1] == s1[i-1])
                            dp[i][j][k] = true;
                    else
                        dp[i][j][k] = false;
                }
                else
                {
                    if(dp[i][j][k-1] == true)
                        dp[i][j][k] = true;
                    else if(dp[i-1][j][k-1] == true && s3[k-1] == s1[i-1])
                            dp[i][j][k] = true;
                    else if(dp[i][j-1][k-1] == true && s3[k-1] == s2[j-1])
                            dp[i][j][k] = true;
                    else
                        dp[i][j][k] = false;
                }
            }
        }
    }
    return dp[s1.size()][s2.size()][s3.size()];
}

int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    printf("%d\n", isInterleave(s1, s2, s3));
    return 0;
}
