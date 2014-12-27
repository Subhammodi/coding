#include <stdio.h>
#include <iostream>
#include <string.h>

int main()
{
	int cases, nodes, i, j, count, query, n_1, n_2, tempp, root, ans;
	scanf("%d", &cases);
	int temp = cases;
	while(cases--)
	{
		scanf("%d", &nodes);
		int *parent = new int[nodes];
		bool *visited = new bool[nodes];
		memset(visited, 0, nodes*sizeof(bool));

		for(i=0; i<nodes; i++)
		{
			scanf("%d", &count);
			for(j=0; j<count; j++)
			{
				scanf("%d", &tempp);
				visited[tempp-1] = true;
				parent[tempp-1] = i;
			}
		}

		for(i=0; i<nodes; i++)
			if(visited[i] == false)
				break;
		root = i;
		parent[root] = root;

		scanf("%d", &query);
		printf("Case %d:\n", temp - cases);
		for(i=0; i<query; i++)
		{
			scanf("%d%d", &n_1, &n_2);
			memset(visited, 0, nodes*sizeof(bool));

			tempp = n_1-1;
			visited[tempp] = true;
			while(parent[tempp] != tempp)
			{
				tempp = parent[tempp];
				visited[tempp] = true;
			}

			tempp = n_2-1;
			ans = tempp+1;
			while(visited[tempp] == false)
			{
				tempp = parent[tempp];
				ans = tempp + 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
