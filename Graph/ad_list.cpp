#include<iostream>
#include<stdio.h>
#include<stdlib.h>

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
void printList(vertex *);

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

void printList(vertex *graph)
{
	int i;
	for(i=0;i<V;i++)
	{
		printf("(%d)", i+1);
		node *temp = graph[i].next;
		while(temp!=NULL)
		{
			printf("->%d",temp->vertexkey);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	printf("Enter the number of vertices in the graph :\n");
	scanf("%d", &V);
	vertex *graph = createGraph(V);
	insertEdge(1, 2, graph);
	insertEdge(2, 3, graph);
	printf("Number of edges in the graph :  %d\n", E);
	printList(graph);
	insertVertex(&graph);
	insertEdge(4, 1, graph);
	printf("Number of edges in the graph :  %d\n", E);
	printList(graph);
}
