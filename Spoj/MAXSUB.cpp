#include<stdio.h>
#include<math.h>

long long int power(long long int count)
{
    long long int answer = 1;
    long long int i;

    for(i=0; i<count; i++)
        answer = (answer*2)%1000000009;

    return answer;
}

int main()
{

	int cases, i, j, n;

	long long int minneg, sum, zerocount, mincount;
	bool allzero;
	bool allneg;

	scanf("%d",&cases);

	for(i=0; i<cases; i++)
	{
		sum = 0;
		zerocount = 0;
		minneg = 0;
		allzero = true;
		allneg = true;
		mincount = 0;
		scanf("%d",&n);

		long long int *arr = new long long int[n];

		for(j=0; j<n; j++)
		{
			scanf("%lld",&arr[j]);

			if(arr[j] != 0)
				allzero = false;

			if(arr[j] >= 0)
				allneg = false;

			if(arr[j] < 0)
			{
				if(minneg == 0)
					minneg = arr[j];
				if(arr[j] > minneg)
					minneg = arr[j];
			}

			if(arr[j] == 0)
				zerocount++;

			if(arr[j] > 0)
				sum += arr[j];
		}

		if(allzero == true)
			printf("0 %lld\n", power(zerocount) - 1);
		else if(allneg == true)
		{
			for(j=0; j<n; j++)
				if(arr[j] == minneg)
					mincount++;

			printf("%lld %lld\n", minneg, mincount);
		}
		else
			printf("%lld %lld\n", sum, power(zerocount));
	}
	return 0;
}
