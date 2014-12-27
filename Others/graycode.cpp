#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        if(n==0)
            return ans;
        string data(n, '0');
        bool flag = true;
        bool flag2 = true;
        int i, j;
        while(flag)
        {
            for(i=n-1; i>=0; i--)
            {
                string temp = data;
                if(data[i] == '0')
                    temp[i] = '1';
                else
                    temp[i] = '0';
                flag2 = true;
                for(j=0; j<ans.size(); j++)
                {
                    if(ans[j] == con(temp))
                    {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2 != false)
                {
                    ans.push_back(con(temp));
                    data = temp;
                    break;
                }
            }
            if(flag2 == false)
                flag = false;
        }
        return ans;
    }

    int con(string s) {
        int i, r=0;
        for(i = s.size()-1; i >=0 ; i--)
            r += (s[i] - '0')*pow(2, s.size()-i-1);
        return (int)r;
    }
};

int main()
{
	Solution obj;
	vector<int> output = obj.grayCode(5);
	for(int i=0; i<output.size(); i++)
		printf("%d\t", output[i]);
	printf("\n");
	return 0;
}
