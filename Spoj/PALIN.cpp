#include <iostream>

using namespace std;

int main()
{
    long int reverse(long int i);
   long int k[1000],j;
   int t,i;
   cin>>t;
   for(i=0;i<t;i++)
        cin>>k[i];
    for(i=0;i<t;i++)
    {
        for(j=k[i]+1;j<1000000;j++)
        {
            if(j==reverse(j))
            {
                cout<<j<<endl;
                break;
            }
        }
    }
}

long int reverse(long int i)
{
    long int rev=0;
    while(i)
    {
        rev=(rev*10)+(i%10);
        i/=10;
    }
    return rev;
}

/*#include<stdio.h>
#include<cmath>

using namespace std;

int reverse(int);

int main()
{
    int cases, i, k, j;
	int temp, temp1, temp2, temp3;
    int a, length;
    scanf("%d",&cases);

    for(i=0;i<cases;i++)
    {
        scanf("%d",&a);
		length = floor(log10(a)) + 1;
		temp1 = length;
		temp2 = a;
		temp = 0;
		temp3=0;

		if(length%2==0)
		{
			//printf("sdfsd\n");
			for(j=0;j<(length/2);j++)
			{
				//printf("sdfsd\n");
				temp = temp*10 + temp2/pow(10.0,temp1-1);
				printf("%d\n",temp);
				temp3 = temp3 + pow(10.0,j)*(int)(temp2/pow(10.0,temp1-1));
				//printf("%d\n",temp3);
				temp2 = temp2 - pow(10.0,temp1-1)*(int)(temp2/pow(10.0,temp1-1));
				//printf("%d\n",temp2);
				temp1--;
			}
			printf("%d\n",temp);
			printf("%d\n",temp3);
			k = pow(10.0,length/2);
			printf("%d\n",k);
			temp = temp3 + temp*k;
			//printf("%d\n",temp);
			//printf("%d\n",a);
			if(temp>a)
			{
				//printf("sdfsfsfsd\n");
				printf("%d\n",temp);
			}
		}
		else
		{
		}
    }
    return 0;
}
*/
/*int reverse(int p)
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
*/
