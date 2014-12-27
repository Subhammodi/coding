#include <stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

int partition(int *arr, int start, int end) {
	int pivot = start;
	int left = start, right = end;
	while(left < right) {
		while(left < end && arr[left] <= pivot)
			left++;
		while(right > start && arr[right] >= arr[pivot])
			right--;
		if(left < right)
			swapp(&arr[left], &arr[right]);
	}
	swapp(&arr[right], &arr[pivot]);
	return right;
}

void quicksort(int *arr, int start, int end) {
	if(start<end) {
		int mid = partition(arr, start, end);
		quicksort(arr, start, mid-1);
		quicksort(arr, mid+1, end);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	quicksort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

