#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

vector<vector<int> > filter(int n, int k, set<int> excl) {
    vector<vector<int> > output;
    if(k==0 || n==0 || k>n)
        return output;
    else if(k == 1)
    {
        for(int i=1;i<=n;i++)
        {
            if(excl.find(i) == excl.end())
            {
                vector<int> dummy;
                dummy.push_back(i);
                output.push_back(dummy);
            }
        }
        return output;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(excl.find(i) == excl.end())
            {
                excl.insert(i);
                vector<vector<int> > temp = filter(n, k-1, excl);
                for(int j=0; j< temp.size(); j++)
                {
                    vector<int> dummy;
                    dummy.push_back(i);
                    for(int k=0; k< temp[j].size(); k++)
                        dummy.push_back(temp[j][k]);
                    output.push_back(dummy);
                }
            }
        }
        return output;
    }
}

vector<vector<int> > combine(int n, int k) {
    set<int> temp;
    return filter(n, k, temp);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int> > output = combine(n,k);
    for(int i=0; i<output.size();i++)
    {
        for(int j=0; j<output[i].size();j++)
        {
            printf("%d\t", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}
