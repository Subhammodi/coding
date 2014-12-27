#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
int rw[4] = {0,0,-1,1};
int cl[4] = {-1,1,0,0};
int N;

bool issafe(char **arr, int i, int j, char curr) {
	if(i>=0 && j>=0 && i<N && j <N && arr[i][j] == curr)
		return true;
	return false;
}

int getcount(char **arr, string input, int i, int j, int val) {
	if(val == input.size())
		return 1;
	int ans = 0;
	for(int k=0; k<4; k++) {
		if(issafe(arr, i+rw[k], j+cl[k], input[val])) {
			ans += getcount(arr, input, i+rw[k], j+cl[k], val+1);
		}
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	char temp;
	char **arr = new char*[N];
	for(int i=0; i<N; i++) {
        arr[i] = new char[N];
		for(int j=0; j<N; j++) {
			do {
				temp = getchar();
			}while(isspace(temp));
			arr[i][j] = temp;
		}
	}
	string input;
	cin >> input;
	int ans =0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(arr[i][j] == input[0])
				ans += getcount(arr, input, i, j, 1);
		}
	}
	cout << ans << endl;
	return 0;
}
