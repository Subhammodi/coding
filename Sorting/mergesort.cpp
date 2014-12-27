#include "header.hpp"

void mergesort(float *, float *, int, int);
void merge(float *, float *, int, int, int);

int main()
{
	int n;
	int i, j, k;
	scanf("%d",&n);

	float *arr = new float[n];
	float *temp_arr = new float[n];

	for(i=0;i<n;i++)
		scanf("%f",&arr[i]);

	mergesort(arr, temp_arr, 0, n-1);

    for(i=0;i<n;i++)
        printf("%f\t",arr[i]);

    printf("\nNumber of comparisons : %d\n",comparisons);
    return 0;
}

void mergesort(float *arr, float *temp_arr, int lower, int upper)
{
	int mid = (lower + upper) / 2;

	if(lower < upper)
	{
		mergesort(arr, temp_arr, lower, mid);
		mergesort(arr, temp_arr, mid+1, upper);
		merge(arr, temp_arr, lower, mid, upper);
	}
}

void merge(float *arr, float *temp_arr, int lower, int mid, int upper)
{
	int i = lower;
	int l = lower;
	int m = mid + 1;
	int k;

	while((l<=mid)&&(m<=upper))
	{
		if(arr[l] <= arr[m])
		{
			temp_arr[i] = arr[l];
			l++;
			comparisons++;
		}
		else
		{
			temp_arr[i] = arr[m];
			m++;
			comparisons++;
		}
		i++;
	}

	if(l>mid)
		for(k=m; k <= upper; k++, i++)
			temp_arr[i] = arr[k];
	else
		for(k = l; k <= mid; k++, i++)
			temp_arr[i] = arr[k];

	for(k = lower ;k <= upper; k++)
		arr[k] = temp_arr[k];

}
