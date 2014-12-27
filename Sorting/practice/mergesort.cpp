#include<stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void merge(int *arr, int start, int mid, int end) {
	int *temp = new int[end-start+1];
	int i = start, j = mid+1;
	int k=0;
	while(i<=mid && j<=end) {
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	if(i<=mid)
		for(int j=i; j<=mid; j++)
			temp[k++] = arr[j];

	if(j<=end)
		for(int i=j; i<=end; i++)
			temp[k++] = arr[i];
		
	for(int i=start; i<=end; i++)
		arr[i] = temp[i];
}

void mergesort(int *arr, int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;
		mergesort(arr, 0, mid);
		mergesort(arr, mid+1, end);
		merge(arr, 0, mid, end);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	mergesort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

