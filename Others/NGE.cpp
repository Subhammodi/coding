#include <stdio.h>
#include <stack>
#include <stdlib.h>

using namespace std;

int *nge(int arr[], int n){
	int *ans = new int[n];
	memset(ans, -1, n*sizeof(int));
	stack<int> data;
	data.push(0);
	for(int i=1; i<n; i++) {
		while(!data.empty() && arr[data.top()] > arr[i]) {
			ans[data.top()] = i;
			data.pop();
		}
		data.push(i);
	}
	return ans;
}

int main()
{
	int arr[] = {11, 13, 21, 3, 6, 5, 7};
	int *ans = nge(arr, sizeof(arr)/sizeof(arr[0]));
	for(int i=0; i< (sizeof(arr)/sizeof(arr[0])); i++)
		if(ans[i] != -1)
			printf("%d..%d\n", arr[i], arr[ans[i]]);
		else
			printf("%d..%d\n", arr[i], -1);
	return 0;
}
