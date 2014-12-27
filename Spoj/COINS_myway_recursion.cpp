#include<stdio.h>
#include<iostream>

using namespace std;

long long int *arr = new long long int[10000];

long long int count(long long int i)
{
    if(i==0)
        return arr[i];
	else if ((i<10000)&&(arr[i]!=0)&&(i>0))
           return arr[i];
	else if(i>=(i/2+i/3+i/4))
	{
		if(i<10000)
			arr[i]=i;
		return i;
	}
	else
	{
		if(i<10000)
		{
			arr[i] = count(i/2) + count(i/3) + count(i/4);
			return arr[i];
		}
		else
			return (count(i/2) + count(i/3) + count(i/4));
    }
}

int main()
{
	long long int input, temp;
	arr[0]=0;
	while(scanf("%lld",&input)>0)
		printf("%lld\n",count(input));
    return  0;
}
