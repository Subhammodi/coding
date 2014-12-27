#include<stdio.h>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int *arr, int lower, int upper)
{
	int i = lower;
	int j = upper;
	int pivot = lower;

	while(i<j)
	{
		while(i < upper && arr[i] <= arr[pivot])
			i++;

		while(j > lower && arr[j] >= arr[pivot])
			j--;

        if(arr[i] > arr[j] && i<j)
            swap(&arr[i], &arr[j]);
	}
    swap(&arr[pivot], &arr[j]);
	return j;
}

void quicksort(int *arr, int lower, int upper)
{
    int pivot_index;
	if(lower < upper)
	{
		pivot_index = partition(arr, lower, upper);
		quicksort(arr, lower, pivot_index - 1);
		quicksort(arr, pivot_index + 1, upper);
    }
}

int main()
{
	int i, j, no, stamp, party, answer;
	bool flag;
	scanf("%d", &no);

	for(i=0;i<no;i++)
	{
        flag = true;
		answer = 0;
		scanf("%d", &stamp);
		scanf("%d", &party);

		int *tic = new int[party];
		for(j=0;j<party;j++)
			scanf("%d", &tic[j]);

		quicksort(tic, 0, party-1);

		int sum = 0;
		if(sum >= stamp)
		{
			printf("Scenario #%d:\n%d\n",i+1, answer);
			continue;
		}

		for(j=party-1;j>=0;j--)
		{
			answer++;
			sum += tic[j];
			if(sum >= stamp)
			{
				flag = false;
				printf("Scenario #%d:\n%d\n",i+1, answer);
				break;
			}
		}
		if(flag == true)
			printf("Scenario #%d:\nimpossible\n", i+1);
	}
	return 0;
}
