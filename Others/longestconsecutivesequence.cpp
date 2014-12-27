#include<map>
#include<stdio.h>
#include<vector>

using namespace std;

int longestConsecutive(vector<int> &num) {
    if(num.size() == 0)
        return 0;
    if(num.size() == 1)
        return 1;
    map<int, int> parent;
    for(int i=0; i< num.size(); i++)
        parent[num[i]] = num[i];
    map<int, int>::iterator it = parent.end();
    it--;
    for(; it != parent.begin();it--)
    {
        if(parent.find(it->first+1) != parent.end())
            parent[it->first] = parent[it->first+1];
        if(parent.find(it->first-1) != parent.end())
            parent[it->first-1] = parent[it->first];
    }

    int ans = 1;
    for(int i=0; i< num.size(); i++)
    {
        if((parent[num[i]] - num[i]) >= ans)
            ans = parent[num[i]] - num[i]+1;
    }
    return ans;
}

int main()
{
    vector<int> input;
    input.push_back(-1);
    input.push_back(0);
    /*input.push_back(200);
    input.push_back(1);
    input.push_back(3);
    input.push_back(2);
    input.push_back(42);
    input.push_back(43);
    input.push_back(1);
    input.push_back(6);
    input.push_back(9);
    input.push_back(200);
    input.push_back(1);
    input.push_back(5);
    input.push_back(8);
    input.push_back(200);
    input.push_back(7);
    input.push_back(3);*/
    printf("%d\n", longestConsecutive(input));
    return 0;
}
