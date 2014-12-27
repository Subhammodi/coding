#include<stdio.h>

using namespace std;

void swapp(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

void bubblesort(int *arr, int n) {
	bool chang = true;
	while(chang) {
		chang = false;
		for(int j=1; j<n; j++) {
			if(arr[j] < arr[j-1]) {
				chang = true;
				swapp(&arr[j], &arr[j-1]);
			}
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

	bubblesort(arr, n);

	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}

