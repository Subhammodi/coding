#include<stdio.h>
#include<math.h>

using namespace std;

int reverse(int);

int main()
{
    int cases, i;
    int a, b;
    scanf("%d",&cases);

    for(i=0;i<cases;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);

        a = reverse(a);
        b = reverse(b);

        printf("%d\n",reverse(a+b));
    }
    return 0;
}

int reverse(int p)
{
    int ulta=0;
    int length;
    if(p!=0)
        length = floor(log10(p)) + 1;
    else
        return 0;

    int temp = length;
    while(temp>0)
    {
        ulta += (pow(10,length-temp))*(floor)(p/pow(10,temp-1));
        p = fmod(p, pow(10,temp-1));
        temp--;
    }
    return ulta;
}
