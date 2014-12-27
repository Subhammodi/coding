#include<stdio.h>
#include<string>
#include<iostream>
#include <sstream>

using namespace std;

string countAndSay(int n) {
    string temp, ans = "";
    if(n==0)
        return ans;
    ans = "1";
    int i, j, k, countt, flip;
    for(i=2; i<=n;i++)
    {
        j = 0;
        temp = "";
        while(j <= (ans.length()-1))
        {
            flip = ans[j];
            countt = 0;
            while((j <= (ans.length()-1)) && ans[j] == flip)
            {
                countt++;
                j++;
            }
            stringstream ss;
            ss << countt;
            temp = temp + ss.str();
            temp += flip;
        }
        ans = temp;
    }
    return ans;
}

int main()
{
    cout << countAndSay(4) << endl;
    return 0;
}
