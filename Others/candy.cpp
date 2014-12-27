#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

int candy(vector<int> &ratings)
{

}

int main()
{
    vector<int> input;
    int n, temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        input.push_back(temp);
    }

    printf("%d\n", candy(input));
    return 0;
}
