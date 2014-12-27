#include<stdio.h>
#include<vector>

using namespace std;

int search(vector<int> prices, int left, int right) {
    if(left >= right)
        return 0;
    else
    {
        int mid = (left + right)/2;
        int temp1 = search(prices, left, mid);
        int temp2 = search(prices, mid+1, right);
        int minn = prices[left], maxx = prices[mid+1];
        for(int i=0; i<=mid; i++)
            if(prices[i] < minn)
                minn = prices[i];
        for(int i=mid+1; i<=right; i++)
            if(prices[i] > maxx)
                maxx = prices[i];
        int ans = max(temp1, temp2);
        if(maxx > minn)
            ans = max(temp1, (maxx-minn));
        return ans;
    }
}

int maxProfit(vector<int> prices) {
    if(prices.size() == 0)
        return 0;
    return search(prices, 0, prices.size() - 1);
}

int main()
{
    vector<int> input;
    input.push_back(6);
    input.push_back(6);
    input.push_back(6);
    input.push_back(2);
    input.push_back(7);
    input.push_back(13);
    printf("%d\n", maxProfit(input));
}
