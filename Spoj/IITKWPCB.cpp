#include<stdio.h>
#include<math.h>

long long int gcd(long long int u, long long int v)
{
    return (v != 0)?gcd(v, u%v):u;
}

int main()
{
	int cases, i;
	long long int answer, input, j;
	scanf("%d",&cases);

	for(i=0; i<cases; i++)
	{
		scanf("%lld",&input);
		answer = input/2;
		if(input%2 == 1)
            printf("%lld\n",answer);
        else if(input%12 == 0)
                printf("%lld\n",answer-1);
        else
        {
            for(j=answer; j>=0; j--)
            {
                if(gcd(input, j) == 1)
                {
                    printf("%lld\n",j);
                    break;
                }
            }
        }
	}
	return 0;
}
