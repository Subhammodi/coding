#include <stdio.h>
#include <climits>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

pair<int, int> mcs(int A[], int start, int end) {
	pair<int, int> ans;
    int curr_ans = A[start], prev = start;

    for(int j=(start+1); j<=end; j++)
	{
		if(curr_ans <= 0) {
			curr_ans = A[j];
			prev = j;
		}
		else
			curr_ans = curr_ans + A[j];
	}
	ans.first = curr_ans;
	ans.second = prev;
	return ans;
}

int main()
{
	int n, start, end;
	time_t t;
	srand((unsigned) time(&t));
	scanf("%d", &n);
	int *arr = new int[n];
	for(int i=0; i<n; i++)
		arr[i] = rand()%10;
		//scanf("%d", &arr[i]);

	int ans = arr[0], curr_ans = arr[0], prev = 0;
	map<int,int> data;
	pair<int, int> ret;
	data[arr[0]] = 0;

	for(int i=1; i<n; i++) {
		if(curr_ans <= 0) {
			curr_ans = arr[i];
			prev = i;
		}
		else {
			if(data.find(arr[i]) == data.end() || prev > data[arr[i]])
				curr_ans += arr[i];
			else {
				ret = mcs(arr, data[arr[i]]+1, i);
				curr_ans = ret.first;
				prev = ret.second;
			}
		}
		data[arr[i]] = i;
		if(curr_ans > ans){
			ans = curr_ans;
			start = prev;
			end = i;
		}
	}

	printf("Ans = %d\nstart = %d\nend = %d\n", ans, start, end);
	return 0;
}
