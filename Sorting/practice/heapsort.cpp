#include<stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void max_heapify(int *arr, int n, int start) {
	int i=start;
	while((2*i+1) < n)
	{
		int l = 2*i+1;
    	int r = 2*i+2;
    	int largest = i;
	    if (l < n && arr[l] > arr[i])
	        largest = l;
	    if (r < n && arr[r] > arr[largest])
	        largest = r;
	    if (largest == i)
	    	break;
        swapp(&arr[i], &arr[largest]);
        i = largest;
	}
	return;
}

void createheap(int *arr, int n) {
	for(int i=(n/2-1); i>=0; i--)
		max_heapify(arr, n, i);
	return;
}

void extract_max(int *arr, int n) {
	swapp(&arr[0], &arr[n-1]);
	max_heapify(arr, n-1, 0);
}

void heapsort(int *arr, int n) {
	for(int i=0; i<n; i++)
		extract_max(arr, n-i);
}

int main()
{
	int n;
	scanf("%d", &n);
	int curr = n;
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	createheap(arr, n);
	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	printf("\n\n");
	heapsort(arr, curr);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}
