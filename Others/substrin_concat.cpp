#include<stdio.h>
#include<string>
#include<vector>
#include<trl/unordered_map>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> output;
    if(S.size() < (L[0].size())*L.size())
        return output;
    unordered_map<string, int> to_find;
    unordered_map<string, int> has_find;
    for(int i=0; i<L.size(); i++)
    {
        if(to_find.find(L[i]) == to_find.end())
            to_find[L[i]] = 1;
        else
            to_find[L[i]]++;
    }
    for(int j=0; j<L[0].size(); j++)
    {
        for(int i=0; i<L.size(); i++)
            has_find[L[i]] = 0;
        int begin, end, count = 0;
        for(begin=j, end=j; end< S.size(); end = end+L[0].size())
        {
            if((S.size()-end) >= L[0].size())
            {
                if (to_find.find(S.substr(end, L[0].size())) == to_find.end())
                {
                    begin = end+L[0].size();
                    count = 0;
                    for(int i=0; i<L.size(); i++)
                        has_find[L[i]] = 0;
                    continue;
                }
                has_find[S.substr(end, L[0].size())]++;
                if (has_find[S.substr(end, L[0].size())] <= to_find[S.substr(end, L[0].size())])
                    count++;
                else
                {
                    if(has_find[S.substr(begin, L[0].size())] > to_find[S.substr(begin, L[0].size())])
                    {
                        has_find[S.substr(begin, L[0].size())]--;
                        begin = begin+L[0].size();
                    }
                    else
                    {
                        has_find[S.substr(begin, L[0].size())]--;
                        begin = begin + L[0].size();
                        count--;
                        end = end - L[0].size();
                    }
                }
                if (count == L.size())
                {
                    output.push_back(begin);
                    has_find[S.substr(begin, L[0].size())]--;
                    begin = begin+L[0].size();
                    count--;
                }
            }
        }
    }
    return output;
}

int main()
{
    vector<string> input;
    input.push_back("abc");
    input.push_back("acb");
    vector<int> output = findSubstring("abcacbdeacbabc", input);
    for(int i=0; i<output.size(); i++)
        printf("%d\n", output[i]);
    return 0;
}
