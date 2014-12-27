#include <stdio.h>
#include <climits>

int eggdrop(int n, int k) {
	int dp[n+1][k+1];
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
		dp[i][1] = 1;
	}

	for(int i=0; i<=k; i++)
		dp[1][i] = i;

	for(int i=2; i<=n; i++){
		for(int j=2; j<=k; j++){
			dp[i][j] = INT_MAX;
			for(int l=1; l<=j; l++) {
				
			}
		}
	}
}

int main()
{
	printf("%d\n", eggdrop(0, 0));
	printf("%d\n", eggdrop(1, 0));
	printf("%d\n", eggdrop(0, 1));
	printf("%d\n", eggdrop(1, 1));
	printf("%d\n", eggdrop(3, 3));
	printf("%d\n", eggdrop(3, 5));
	printf("%d\n", eggdrop(5, 2));
	printf("%d\n", eggdrop(5, 3));
	printf("%d\n", eggdrop(8, 2));
	printf("%d\n", eggdrop(8, 4));
	return 0;
}
