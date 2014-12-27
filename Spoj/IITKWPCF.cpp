#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(float *p, float *q)
{
    float temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void quicksort(long long int *arr, long long int lower, long long int upper)
{
    long long int pivot_index;
	if(lower < upper)
	{
		pivot_index = partition(arr, lower, upper);
		quicksort(arr, lower, pivot_index - 1);
		quicksort(arr, pivot_index + 1, upper);
    }
}

int partition(long long int *arr, long long int lower, long long int upper)
{
	long long int i = lower;
	long long int j = upper;
	long long int pivot = lower;

	while(i<j)
	{
		while(i < upper && arr[i] <= arr[pivot])
        {
			i++;
        }

		while(j > lower && arr[j] >= arr[pivot])
        {
			j--;
        }

        if(arr[i] > arr[j] && i<j)
            swap(&arr[i], &arr[j]);
	}
    swap(&arr[pivot], &arr[j]);
	return j;
}

bool IsPrime(long long int number)
{
    if(number<2)
        return false;
    if(number==2)
        return true;
    if(number%2==0)
        return false;
    for(long long int i=3;i<=sqrt(number);i += 2)
    {
        if(number%i==0)
            return false;
    }
    return true;
}

int main()
{
	int i, cases;
	scanf("%d",&cases);
	long long int n, temp1, count, j;

	for(i=0; i<cases; i++)
	{
		scanf("%lld",&n);
		if(n <= 0 || n%2 == 1)
			printf("0\n");
		else
		{
		    if(n == 2)
                printf("1 1\n");
            else
            {
				long long int *arr = new long long int[100000];
                count = 0;
                n = n/2;
                for(j=1; j<=(long long int)(sqrt((double)n)); j++)
                {
                    if(n%j == 0)
                    {
                        if(!IsPrime(j))
						{
							count++;
							arr[count-1] = j;
						}
						temp1 = n/j;
						if( (temp1 != j) && (!IsPrime(temp1)) )
						{
							count++;
							arr[count-1] = j;
						}
                    }
                }
				printf("%lld",count);
				quicksort(arr, 0, count - 1);
				for(j=0; j<count; j++)
					printf(" %lld",arr[j]);
				printf("\n");
            }
		}
	}
	return 0;
}
