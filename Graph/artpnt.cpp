#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

int min(int a, int b) {
	return ((a<=b) ? a:b);
}
class Graph {
		int V;
		vector<int> *adj;
		void dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]);
	public:
		Graph(int n) {
			this->V = n;
			this->adj = new vector<int>[n];
		}
		void addEdge(int a, int b);
		void artpnt();

};

void Graph::addEdge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void Graph::dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) {
	static int var = 0;
	visited[u] = true;
	disc[u] = low[u] = ++var;
	int child = 0;

	for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
		if(visited[*it] == false) {
			child++;
			parent[*it] = u;
			dfs(*it, visited, disc, low, parent, ap);

			low[u] = min(low[u], low[*it]);

			if(parent[u] == -1 && child > 1)
				ap[u] = true;
			if(parent[u] != -1 && low[*it]>=disc[u])
                ap[u] = true;
		}
		else
			low[u] = min(low[u], disc[*it]);
	}

}

void Graph::artpnt() {
	bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            dfs(i, visited, disc, low, parent, ap);

    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
}

int main()
{
	cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.artpnt();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.artpnt();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.artpnt();
	return 0;
}
