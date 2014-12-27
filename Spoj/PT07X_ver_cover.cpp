#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Vertex
{
	int vertexnumber;
	int count;
	struct Node *next;
} vertex;

typedef struct Node
{
	int vertexkey;
	struct Node *next;
} node;

int V;

vertex *createGraph(int);
void insertEdge(int, int, vertex *);
void deleteEdge(int, int, vertex *);
int VC(vertex *, int);

vertex *createGraph(int V)
{
	int i;
	vertex *graph = new vertex[V];
	for(i=0;i<V;i++)
	{
		graph[i].vertexnumber = (i+1);
		graph[i].count = 0;
		graph[i].next = NULL;
	}
	return graph;
}

//for undirected graph
void insertEdge(int vertex1, int vertex2, vertex *graph)
{
	//1st vertex
	node *temp1 = new node;
	temp1->vertexkey = vertex2;
	temp1->next = graph[vertex1-1].next;
	(graph)[vertex1-1].next = temp1;
	(graph)[vertex1-1].count++;
	//2nd vertex
	node *temp2 = new node;
	temp2->vertexkey = vertex1;
	temp2->next = graph[vertex2-1].next;
	(graph)[vertex2-1].next = temp2;
	(graph)[vertex2-1].count++;
}

void deleteEdge(int vertex1, int vertex2, vertex *graph)
{
	node *temp;
	node *temp1;

	temp = graph[vertex1-1].next;
	if(temp->vertexkey == vertex2)
		graph[vertex1-1].next = temp->next;
	else
	{
		while(temp!=NULL)
		{
			if(temp->vertexkey == vertex2)
			{
				temp1 = temp;
				temp1->next = temp->next;
				break;
			}
			else
			{
				temp1 = temp;
				temp = temp->next;
			}
		}
	}
	graph[vertex1-1].count--;
	
	temp = graph[vertex2-1].next;
	if(temp->vertexkey == vertex1)
		graph[vertex2-1].next = temp->next;
	else
	{
		while(temp!=NULL)
		{
			if(temp->vertexkey == vertex1)
			{
				temp1->next = temp->next;
				break;
			}
			else
			{
				temp1 = temp;
				temp = temp->next;
			}
		}
	}
	graph[vertex2-1].count--;
}

int VC(vertex *graph, int V)
{
	int i;
	int sum = 0;
	int current, count;
	if(V == 1)
		count =0;
	else
		count = V;
	node *temp;
	while(count != 0)
	{
		for(i=0; i<V; i++)
		{
			if(graph[i].count == 1)
			{
				count--;

				current = (graph[i].next)->vertexkey;
				deleteEdge(i+1, current, graph);
				sum++;

				temp = graph[current-1].next;
				while(temp != NULL)
				{
					if(graph[temp->vertexkey - 1].count == 1)
						count--;
					deleteEdge(current, temp->vertexkey, graph);
					temp = graph[current-1].next;
				}
				count--;
			}
			else
				continue;
		}
	}
	return sum;
}

int main()
{
	int i, S, D;
	scanf("%d", &V);
	vertex *graph = createGraph(V);
	for(i=0; i<(V-1); i++)
	{
		scanf("%d%d", &S, &D);
		insertEdge(S, D, graph);
	}

	printf("%d", VC(graph, V));
}
