#include <stdio.h>
#include <stdlib>
#include <vector>

using namespace std;

typedef pair<int, int> point;

vector<point> neigh(int x, int y, int n) {
	vector<point> near;
	if((y+2) < n){
		if((x+1) < n)
			near.push_back(make_pair(x+1, y+2));
		if((x-1) >= 0)
			near.push_back(make_pair(x-1, y+2));
	}
	if((y-2) >= 0){
		if((x+1) < n)
			near.push_back(make_pair(x+1, y-2));
		if((x-1) >= 0)
			near.push_back(make_pair(x-1, y-2));
	}
	if((x+2) < n){
		if((y+1) < n)
			near.push_back(make_pair(x+2, y+1));
		if((y-1) >= 0)
			near.push_back(make_pair(x+2, y-1));
	}
	if((x-2) >= 0){
		if((y+1) < n)
			near.push_back(make_pair(x-2, y+1));
		if((y-1) >= 0)
			near.push_back(make_pair(x-2, y-1));
	}
	return near;
}

int dfs(int x, int y, int n, int count, int **flag) {
	int ans = 0;
	if(count == n*n)
		return 1;
	vector<point> near = neigh(x, y, n);
	for(vector<point>::iterator it = near.begin(); it != near.end(); it++) {
		if(flag[*it.first][*it.second] == false) {
			flag[*it.first][*it.second] = true;
			ans += dfs(*it.first,*it.second,n,count+1,flag)
		}
	}
	return ans;
}

int main()
{
	int n = ;
	int x = ;
	int y = ;
	bool **flag = new bool[n];
	for(int i=0; i<n; i++) {
		flag[i] = new bool[n]
		memset(flag, false, n*sizeof(bool));
	}
	flag[x][y] = true;
	printf("%d\n", dfs(x,y,n,1,flag));
	return 0;
}