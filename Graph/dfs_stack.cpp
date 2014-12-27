#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<stack>

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
void bfs(vertex *, int *, int *, int);

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

void bfs(vertex *graph, int *distance, int *label, int start)
{
	int current, i;
	node *temp;
	distance[start-1] = 0;
	stack<int> storage;
	storage.push(start);

	while(!storage.empty())
	{
		current = storage.top();
		printf("%d->", current);
		storage.pop();
		temp = graph[current-1].next;
		while(temp != NULL)
		{
			if(distance[temp->vertexkey - 1] == 999)
			{
				distance[temp->vertexkey-1] = distance[current-1] + 1;
				label[temp->vertexkey-1] = start;
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
	printf("Enter the number of vertices in the graph :\n");
	scanf("%d", &V);
	vertex *graph = createGraph(V);
	insertEdge(1, 2, graph);
	insertEdge(2, 5, graph);
	insertEdge(5, 1, graph);
	insertEdge(3, 7, graph);
	insertEdge(3, 5, graph);
	insertEdge(4, 7, graph);
	insertEdge(1, 4, graph);
	insertEdge(8, 6, graph);
	insertEdge(8, 9, graph);
	insertEdge(2, 10, graph);
	insertEdge(12, 11, graph);
	int *distance = new int[V];
	int *label = new int[V];

	for(i=1; i<=V; i++)
	{
		distance[i-1] = 999;
		label[i-1] = 999;
	}

	for(i=1; i<=V; i++)
	{
		if(distance[i-1] == 999)
		{
			label[i-1] = i;
			printf("BFS traversal of graph from vertex %d: \n", i);
			bfs(graph, distance, label, i);
			printf("\n");
		}
	}

	printf("\nDistance from start : \n");
	for(i=0; i<V; i++)
		printf("Distance of %d = %d\n", i+1, distance[i]);

	printf("Label of vertices :\n");
	for(i=1; i<=V; i++)
		printf("Vertex %d : (%d)\n", i, label[i-1]);
}
