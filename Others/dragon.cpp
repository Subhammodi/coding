#include <stdio.h>
#include <queue>
using namespace std;

int **dist;

typedef pair<int, int> point;
class OrderByAge
{
	public:
	    bool operator() (point a, point b) {
	        return dist[a.first][a.second] > dist[b.first][b.second];
	    }
};

typedef priority_queue<point, vector<point>, OrderByAge> age_queue;

int func(int **data, int n, int m) {
	age_queue q;
	point temp;
	dist = new int*[n];
	for(int i=0; i<n; i++) {
		dist[i] = new int[m];
		memset(dist[i], 0, m*sizeof(int));
	}
	char **flag = new char*[n];
	for(int i=0; i<n; i++) {
		flag[i] = new char[m];
		for(int j=0; j<m; j++)
			flag[i][j] = 'W';
	}
	q.push(make_pair(0,0));
	dist[0][0] = data[0][0];
	flag[0][0] = 'B';
	while(!q.empty()) {
		temp = q.top();
		printf("%d\t%d\n", temp.first, temp.second);
		q.pop();
		flag[temp.first][temp.second] = 'B';
		if(temp.first == (n-1) && temp.second == (m-1)) {
			printf("\n\n");
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++)
					printf("%d\t", dist[i][j]);
				printf("\n");
			}
			printf("\n\n");
			return dist[temp.first][temp.second];
			break;
		}
		if(temp.first > 0 && data[temp.first-1][temp.second] != -1) {
			if(flag[temp.first-1][temp.second] == 'W') {
				dist[temp.first-1][temp.second] = dist[temp.first][temp.second] + data[temp.first-1][temp.second];
				flag[temp.first-1][temp.second] = 'G';
				q.push(make_pair(temp.first-1, temp.second));
			}
			else
				if(flag[temp.first-1][temp.second] == 'G' && dist[temp.first-1][temp.second] > (dist[temp.first][temp.second] + data[temp.first-1][temp.second])) {

				}
		}
		if(temp.first < (n-1) && data[temp.first+1][temp.second] != -1) {
			if(flag[temp.first+1][temp.second] == 'W') {
				dist[temp.first+1][temp.second] = dist[temp.first][temp.second] + data[temp.first+1][temp.second];
				flag[temp.first+1][temp.second] = 'G';
				q.push(make_pair(temp.first+1, temp.second));
			}
			else
				if(flag[temp.first+1][temp.second] == 'G' && dist[temp.first+1][temp.second] > (dist[temp.first][temp.second] + data[temp.first+1][temp.second])) {

				}
		}
		if(temp.second > 0 && data[temp.first][temp.second-1] != -1) {
			if(flag[temp.first][temp.second-1] == 'W') {
				dist[temp.first][temp.second-1] = dist[temp.first][temp.second] + data[temp.first][temp.second-1];
				flag[temp.first][temp.second-1] = 'G';
				q.push(make_pair(temp.first, temp.second-1));
			}
			else
				if(flag[temp.first][temp.second-1] == 'G' && dist[temp.first][temp.second-1] > (dist[temp.first][temp.second] + data[temp.first][temp.second-1])) {

				}
		}
		if(temp.second < (m-1) && data[temp.first][temp.second+1] != -1) {
			if(flag[temp.first][temp.second+1] == 'W') {
				dist[temp.first][temp.second+1] = dist[temp.first][temp.second] + data[temp.first][temp.second+1];
				flag[temp.first][temp.second+1] = 'G';
				q.push(make_pair(temp.first, temp.second+1));
			}
			else
				if(flag[temp.first][temp.second+1] == 'G' && dist[temp.first][temp.second+1] > (dist[temp.first][temp.second] + data[temp.first][temp.second+1])) {

				}
		}
	}
	return -1;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int **data = new int*[n];
	for(int i=0; i<n; i++) {
		data[i] = new int[m];
		for(int j=0; j<m; j++)
			scanf("%d", &data[i][j]);
	}
	printf("%d\n", func(data, n, m));
	return 0;
}