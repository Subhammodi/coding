#include "header.hpp"

void quicksort(float *, int, int);
int partition(float *, int, int);

int main()
{
	int n;
	int i, j, k;
	scanf("%d",&n);

	float *arr = new float[n];
	for(i=0;i<n;i++)
		scanf("%f",&arr[i]);

	quicksort(arr, 0, n-1);

    for(i=0;i<n;i++)
        printf("%f\t",arr[i]);

    printf("\nNumber of comparisons : %d\n",comparisons);
    return 0;
}

void quicksort(float *arr, int lower, int upper)
{
    int pivot_index;
	if(lower < upper)
	{
		pivot_index = partition(arr, lower, upper);
		quicksort(arr, lower, pivot_index - 1);
		quicksort(arr, pivot_index + 1, upper);
    }
}

int partition(float *arr, int lower, int upper)
{
	int i = lower;
	int j = upper;
	int pivot = lower;

	while(i<j)
	{
		while(i < upper && arr[i] <= arr[pivot])
        {
            comparisons++;
			i++;
        }

		while(j > lower && arr[j] >= arr[pivot])
        {
            comparisons++;
			j--;
        }

        if(arr[i] > arr[j] && i<j)
            swap(&arr[i], &arr[j]);
	}
    swap(&arr[pivot], &arr[j]);
	return j;
}
