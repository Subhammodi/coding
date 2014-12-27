#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int count1;
    int length;
    int i,j;
    long int countt;
    long int arr;

    scanf("%d",&count1);

    for(i=0;i<count1;i++)
    {
        countt = 0;
        scanf("%ld",&arr);
        length = (log10(arr))/(log10(5));
        for(j=0;j<length;j++)
        {
            countt += arr/pow(5,j+1);
        }
        printf("%ld\n",countt);
    }

    return 0;
}
