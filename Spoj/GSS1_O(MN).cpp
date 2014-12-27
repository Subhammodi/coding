#include<stdio.h>
#include<string.h>

int main()
{
	int n, i, j, cases, left, right;
	long long int answer;

	scanf("%d", &n);

	long long int *arr = new long long int[n];

	for(i=0;i<n;i++)
		scanf("%lld", &arr[i]);

    scanf("%d", &cases);

    for(i=0;i<cases;i++)
    {
        scanf("%d", &left);
        scanf("%d", &right);

		long long int *max = new long long int[right-left+1];
		memset(max, 0, (right-left+1)*sizeof(long long int));

        answer = arr[left-1];

        for(j=(left-1); j<=(right-1); j++)
		{
			if(j == (left-1))
				max[j] = arr[j];
			else
			{
				if(max[j-1] <= 0)
					max[j] = arr[j];
				else
					max[j] = max[j-1] + arr[j];
			}

            if(max[j] > answer)
                answer = max[j];
		}

        printf("%lld\n", answer);
    }

    return 0;
}
