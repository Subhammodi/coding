#include<stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void insersort(int *arr, int n) {
	int j;
	for(int i=0; i<n; i++) {
		j=i;
		while(j>0) {
			if(arr[j] < arr[j-1])
				swapp(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	insersort(arr, n);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

