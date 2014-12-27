#include "header.hpp"

float quickselect(float *, int, int, int);
int partition(float *, int, int, int);

int main()
{
	int n;
	int i, j, k;
	int rank;
	scanf("%d",&n);
	float answer;

	float *arr = new float[n];
	for(i=0;i<n;i++)
		scanf("%f",&arr[i]);

	scanf("%d",&rank);

	answer = quickselect(arr, 0, n-1, rank);

    //for(i=0;i<n;i++)
        //printf("%f\t",arr[i]);

	printf("\n%f\t",answer);

    return 0;
}

float quickselect(float *arr, int lower, int upper, int rank)
{
    int pivot_index;
	if(lower < upper)
	{
		pivot_index = partition(arr, lower, upper, arr[lower]);
		if(rank == pivot_index+1)
			return arr[pivot_index];
		else if(rank < pivot_index+1)
			return quickselect(arr, lower, pivot_index - 1, rank);
		else
			return quickselect(arr, pivot_index + 1, upper, rank);
    }
	else
		return arr[lower];
}

int partition(float *arr, int lower, int upper, int pivot)
{
	int i = lower;
	int j = upper;

	int k, pivot_index;
	for(k=lower;k<=upper;k++)
		if(arr[k]==pivot)
			break;
	swap(&arr[k], &arr[lower]);
	pivot_index = lower;

	while(i<j)
	{
		while(i < upper && arr[i] <= arr[pivot_index])
			i++;

		while(j > lower && arr[j] >= arr[pivot_index])
			j--;

        if(arr[i] > arr[j] && i<j)
            swap(&arr[i], &arr[j]);
	}
    swap(&arr[pivot_index], &arr[j]);

	return j;
}
