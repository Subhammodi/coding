#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int reverse(int x) {
        int ans = 0;
        bool flag = false;
        if(x < 0)
        {
            flag = true;
            x = abs(x);
        }
        if(x < 10)
        {
            ans = (flag == true) ? (-1)*x : x;
            return ans;
        }
        else
        {
            int temp = x, digit = 0;
            double tempp;
            while(temp > 0)
            {
                temp /= 10;
                digit++;
            }
            while(x > 0)
            {
                tempp = double(digit-1);
                tempp = pow(10.0, tempp);
                ans += (x%10)*(int)tempp;
                x /= 10;
                digit--;
            }
            ans = (flag == true) ? (-1)*ans : ans;
            return ans;
        }
    }

int main()
{
    printf("%d\t%d\n", reverse(123), reverse(-123));
    return 0;
}
