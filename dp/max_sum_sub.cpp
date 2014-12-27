#include <stdio.h>
#include<stdlib.h>
#include <iostream>

int mss(int *arr, int n, int &start, int &finish)
{
	int i;
	int curr = arr[0];
	int max = curr;
	int temp = 0;
	for(i=1; i<n; i++)
	{
		if(curr <= 0) {
			curr = arr[i];
			temp = i;
		}
		else
			curr = curr + arr[i];

		if(max < curr) {
			max = curr;
			start = temp;
			finish = i;
		}
	}
	return max;
}

int main()
{
	int n, i;
	while(1)
	{
		scanf("%d", &n);
		int *arr = new int[n];
		int start, finish;
		for(i=0; i<n; i++)
            scanf("%d", arr + i);
		printf("Ans = %d\n\n", mss(arr, n, start, finish));
		printf("left = %d\tfinish = %d\n", start, finish);
	}
	return 0;
}
