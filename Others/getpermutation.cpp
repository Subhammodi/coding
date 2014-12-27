#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include<vector>

using namespace std;

int fact(int n) {
    int ans = 1;
    for(int i=1; i<=n; i++)
        ans = ans*i;
    return ans;
}

string getPermutation(int n, int k) {
    string ans = "";
    if(k > fact(n) || k < 1)
        return ans;
    int temp, temp1;
    double tem, tem1;
    vector<int> mp;
    for(int i=1; i<=n; i++)
        mp.push_back(i);

    for(int i=1; i<=n; i++)
    {
        stringstream ss;

        temp = int(ceil((double)k/fact(n-i)));

        if(i == n)
            temp1 = mp[0];
        else
            temp1 = mp[temp-1];
        ss << temp1;
        ans += ss.str();
        for(vector<int>::iterator it = mp.begin(); it!=mp.end(); it++)
            if(*it == temp1)
            {
                mp.erase(it);
                break;
            }

        k = k%fact(n-i);
        if(k == 0)
            k = fact(n-i);
    }
    return ans;
}

int main()
{
    cout << getPermutation(3, 1) << endl;
    return 0;
}
