#include "header.hpp"

float mom(float *, int, int, int);
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
        //arr[i] = i;
		scanf("%f",&arr[i]);

	scanf("%d",&rank);
	printf("\n%f\t",mom(arr, 0, n-1, rank));

    return 0;
}

float mom(float *arr, int lower, int upper, int rank)
{
	if(lower == upper)
		return arr[lower];
	int i, j, pivot_index;
	int left, right;
	int pivot;
    int block = (upper - lower + 5)/5;
	float *temp = new float[block];

	for(i=0;i<block;i++)
	{
		left = lower + i*5;
		right = left + 4;
		if(right > upper)
            right = upper;
		temp[i] = quickselect(arr, left, right, (right + left)/2+1);
	}

    pivot = mom(temp, 0, block-1, block/2+1);

	pivot_index = partition(arr, lower, upper, pivot);

	if(rank == pivot_index + 1)
		return arr[pivot_index];
	else if(rank < pivot_index + 1)
		return mom(arr, lower, pivot_index - 1, rank);
	else
		return mom(arr, pivot_index + 1, upper, rank);
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
