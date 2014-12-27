#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>

using namespace std;

typedef struct Vertex
{
	int vertexnumber;
	struct Node *next;
} vertex;

typedef struct Node
{
	int vertexkey;
	struct Node *next;
} node;

int V;
int E=0;

vertex *createGraph(int);
void insertVertex(vertex **);
void insertEdge(int, int, vertex *);
void bfs(vertex *, int *, int);

vertex *createGraph(int V)
{
	int i;
	vertex *graph = new vertex[V];
	for(i=0;i<V;i++)
	{
		graph[i].vertexnumber = (i+1);
		graph[i].next = NULL;
	}
	return graph;
}

void insertVertex(vertex **graph)
{
	V++;
	vertex *temp = (vertex *)realloc(*graph,V*sizeof(vertex));
	if(temp != NULL)
	{
		*graph = temp;
		(*graph)[V-1].vertexnumber = V;
		(*graph)[V-1].next = NULL;
	}
	else
		printf("Error re-allocating memory.\n");
}

//for undirected graph
void insertEdge(int vertex1, int vertex2, vertex *graph)
{
	E++;
	//1st vertex
	node *temp1 = new node;
	temp1->vertexkey = vertex2;
	temp1->next = graph[vertex1-1].next;
	(graph)[vertex1-1].next = temp1;
	//2nd vertex
	node *temp2 = new node;
	temp2->vertexkey = vertex1;
	temp2->next = graph[vertex2-1].next;
	(graph)[vertex2-1].next = temp2;
}

void bfs(vertex *graph, int *distance, int start)
{
	int current, i;
	node *temp;
	distance[start-1] = 0;
	queue<int> storage;
	storage.push(start);

	while(!storage.empty())
	{
		current = storage.front();
		printf("%d->", current);
		storage.pop();
		temp = graph[current-1].next;
		while(temp != NULL)
		{
			if(distance[temp->vertexkey - 1] == 999)
			{
				distance[temp->vertexkey-1] = distance[current-1] + 1;
				storage.push(temp->vertexkey);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
}

int main()
{
	int i, j;
	bool bipartite = true;
	vector<vector<int> > list;
	multimap<int, int> hash;
	multimap<int, int>::iterator it;

	printf("Enter the number of vertices in the graph :\n");
	scanf("%d", &V);
	int *distance = new int[V];
	for(i=1; i<=V; i++)
		distance[i-1] = 999;
	vertex *graph = createGraph(V);
	insertEdge(1, 2, graph);
	insertEdge(2, 5, graph);
	insertEdge(3, 5, graph);
	insertEdge(4, 3, graph);
	insertEdge(4, 1, graph);
	bfs(graph, distance, 2);

	/*
	printf("\n");
	for(i=1; i<=V; i++)
		hash.insert(pair<int, int>(distance[i-1], i));
	it = hash.begin();
	for(i=1; i<=V; i++)
	{
		if(hash.find(i-1) != hash.end())
		{
			vector<int> row;
			list.push_back(row);
			while((*it).first == i-1)
			{
				list[i-1].push_back(((*it).second));
				it++;
			}
		}
		else
			continue;
	}

	for(i=0; i<list.size(); i++)
	{
		for(j=0; j<list[i].size(); j++)
		{
			printf("%d, ", list[i][j]);
		}
		printf("\n");
	}*/

	printf("\n");
	for(i=1; i<=V; i++)
	{
		node *temp = graph[i-1].next;
		while(temp !=NULL)
		{
			if(distance[(graph[i-1]).vertexnumber - 1] == distance[temp->vertexkey-1])
			{
				bipartite = false;
				break;
			}
			else
				temp = temp->next;
		}
		if(bipartite == false)
			break;
	}

	if(bipartite == false)
		printf("Graph is not Bipartite.\n");
	else
	{
		printf("Graph is Bipartite. Sets are :\nA = ");
		for(i=1; i<=V; i++)
		{
			if(distance[i-1]%2 == 0)
				printf("%d ", i);
		}
		printf("\nB = ");
		for(i=1; i<=V; i++)
		{
			if(distance[i-1]%2 != 0)
				printf("%d ", i);
		}
	}
}
