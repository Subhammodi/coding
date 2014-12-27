#include <iostream>
#include <vector>

using namespace std;

vector <long long> memo(10000000, -1);

long long getMaxVal(long long n)
{
    if ((n < 10000000) && (memo[n] != -1))
    {
           return memo[n];
    }

    if ((n / 2) + (n / 3) + (n / 4) < n)
    {
           if (n < 10000000)
           {
                 memo[n] = n;
         }
         return n;
    }
    else
    {
       if (n < 10000000)
       {
              memo[n] = getMaxVal(n / 2) + getMaxVal(n / 3) + getMaxVal(n / 4);
           return memo[n];
      }
      else
      {
          return getMaxVal(n / 2) + getMaxVal(n / 3) + getMaxVal(n / 4);
      }
    }
}
int main ()
{
    long long n;
    while(cin >> n)
    {
        cout << getMaxVal(n) << endl;
    }
    return 0;
}