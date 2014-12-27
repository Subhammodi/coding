#include<stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void selsort(int *arr, int n) {
	int min;
	for(int i=0; i<n; i++) {
		min = i;
		for(int j=i+1; j<n; j++) {
			if(arr[min] > arr[j])
				min = j;
		}
		if(i!=min)
			swapp(&arr[i], &arr[min]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	selsort(arr, n);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

