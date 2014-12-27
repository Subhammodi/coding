#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void swapp(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

typedef struct Vertex
{
	int vertexnumber;
	struct Node *next;
} vertex;

typedef struct Node
{
	int vertexkey;
	int weight;
	struct Node *next;
} node;

int V;
int E=0;

vertex *createGraph(int);
void insertVertex(vertex **);
void insertEdge(int, int, vertex *);
void prims(vertex *, int *, int *, char **, int *, int, int);

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
void insertEdge(int vertex1, int vertex2, int weight, vertex *graph)
{
	E++;
	//1st vertex
	node *temp1 = new node;
	temp1->vertexkey = vertex2;
	temp1->weight = weight;
	temp1->next = graph[vertex1-1].next;
	(graph)[vertex1-1].next = temp1;
	//2nd vertex
	node *temp2 = new node;
	temp2->vertexkey = vertex1;
	temp2->weight = weight;
	temp2->next = graph[vertex2-1].next;
	(graph)[vertex2-1].next = temp2;
}

class priority_queue
{
    public:
        int max_size;
		int current_size;
		int *arr;

		priority_queue(int a)
		{
			max_size = a;
			current_size = 0;
			arr = new int[a];
		}
		void insert(int, int *, int *);
		int extract_min(int *, int *);
		void decrease(int, int *, int *);
};

void priority_queue::insert(int vertexkey, int *distance, int *pos)
{
	//printf("\n\n%d\n\n", current_size);
	if((current_size + 1) <= max_size)
		arr[current_size] = vertexkey;
	else
		printf("ERROR\n");

	int i = current_size;
	int temp;
	pos[vertexkey-1] = current_size;
	while(i > 0 && (distance[arr[i]-1] < distance[arr[(int)floor((i-1)/2)]-1]))
	{
		temp = pos[arr[i]-1];
		pos[arr[i]-1] = pos[arr[((int)floor((i-1)/2))]-1];
		pos[arr[((int)floor((i-1)/2))]-1] = temp;
		swapp(&arr[i], &arr[((int)floor((i-1)/2))]);
		i = (int)floor((i-1)/2);
	}
	current_size++;
}

int priority_queue::extract_min(int *distance, int *pos)
{
	current_size--;
	int min = arr[0];
	pos[min-1] = 999;
	arr[0] = arr[current_size];
	pos[arr[0]-1] = 0;
	int i=0;
	int temp;
	while((2*i+1) < current_size)
	{
		if((2*i+2) < current_size)
		{
			if( (distance[arr[2*i+1]-1] <= distance[arr[2*i+2]-1]) && (distance[arr[i]-1] > distance[arr[2*i+1]-1]) )
			{
				temp = pos[arr[i]-1];
				pos[arr[i]-1] = pos[arr[2*i+1]-1];
				pos[arr[2*i+1]-1] = temp;
				swapp(&arr[i], &arr[2*i+1]);
				i = 2*i+1;
			}
			else if( (distance[arr[2*i+1]-1] <= distance[arr[2*i+2]-1]) && (distance[arr[i]-1] <= distance[arr[2*i+1]-1]) )
				break;
			else if(distance[arr[i]-1] <= distance[arr[2*i+2]-1])
				break;
			else
			{
				temp = pos[arr[i]-1];
				pos[arr[i]-1] = pos[arr[2*i+2]-1];
				pos[arr[2*i+2]-1] = temp;
				swapp(&arr[i], &arr[2*i+2]);
				i = 2*i+2;
			}
		}
		else
		{
			if(distance[arr[i]-1] <= distance[arr[2*i+1]-1])
				break;
			else
			{
				temp = pos[arr[i]-1];
				pos[arr[i]-1] = pos[arr[2*i+1]-1];
				pos[arr[2*i+1]-1] = temp;
				swapp(&arr[i], &arr[2*i+1]);
				i = 2*i+1;
			}
		}
	}
	return min;
}

void priority_queue::decrease(int vertexkey, int *distance, int *pos)
{
	int i = pos[vertexkey - 1];
	int temp;
	if(i >= current_size)
		printf("Invalid input. Element not present in heap.\n");
	else
	{
		while(i > 0 && distance[arr[i]-1] < distance[arr[(int)floor((i-1)/2)]-1])
		{
			temp = pos[arr[i]-1];
			pos[arr[i]-1] = pos[arr[(int)floor((i-1)/2)]-1];
			pos[arr[(int)floor((i-1)/2)]-1] = temp;
			swapp(&arr[i], &arr[(int)floor((i-1)/2)]);
			i = (int)floor((i-1)/2);
		}
	}
}

void prims(vertex *graph, int *distance, int *label, char **flag, int *pos, int V, int start)
{
	priority_queue heap(V);
	node *temp;
	int current, i;

	distance[start-1] = 0;
	heap.insert(start, distance, pos);
	label[start-1] = start;
	flag[start-1] = "G";

	while(heap.current_size != 0)
	{
		current = heap.extract_min(distance, pos);
		printf("%d->", current);
		flag[current-1] = "B";
		temp = graph[current-1].next;
		while(temp != NULL)
		{
			if(flag[temp->vertexkey - 1] == "W")
			{
				distance[temp->vertexkey-1] = temp->weight;
				heap.insert(temp->vertexkey, distance, pos);
				label[temp->vertexkey-1] = current;
				flag[temp->vertexkey-1] = "G";
				temp = temp->next;
			}
			else if(flag[temp->vertexkey - 1] == "G")
			{
				if((temp->weight) <= distance[temp->vertexkey-1])
				{
					distance[temp->vertexkey-1] = temp->weight;
					heap.decrease(temp->vertexkey, distance, pos);
					label[temp->vertexkey-1] = current;
					flag[temp->vertexkey-1] = "G";
					temp = temp->next;
				}
				else
				{
					temp = temp->next;
				}
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}

int main()
{
	int i, j;
	printf("Enter the number of vertices in the graph :\n");
	scanf("%d", &V);
	vertex *graph = createGraph(V);
	insertEdge(1, 2, 4, graph);
	insertEdge(1, 8, 8, graph);
	insertEdge(2, 8, 11, graph);
	insertEdge(2, 3, 8, graph);
	insertEdge(3, 9, 2, graph);
	insertEdge(9, 7, 6, graph);
	insertEdge(8, 9, 7, graph);
	insertEdge(7, 8, 1, graph);
	insertEdge(6, 7, 2, graph);
	insertEdge(3, 6, 4, graph);
	insertEdge(3, 4, 7, graph);
	insertEdge(4, 6, 14, graph);
	insertEdge(4, 5, 9, graph);
	insertEdge(5, 6, 10, graph);
	int *distance = new int[V];
	int *label = new int[V];
	int *pos = new int[V];
	char **flag = new char *[V];

	for(i=1; i<=V; i++)
	{
		flag[i] = new char[1];
		flag[i] = "W";
		distance[i-1] = 999;
		label[i-1] = 999;
		pos[i-1] = 999;
	}

	printf("MST's traversal of graph from vertex 1: \n");
	prims(graph, distance, label, flag, pos, V, 1);
	printf("\n");

	printf("\nDistance from start : \n");
	for(i=0; i<V; i++)
		printf("Distance of %d = %d\n", i+1, distance[i]);

	printf("Label of vertices :\n");
	for(i=1; i<=V; i++)
		printf("Vertex %d : (%d)\n", i, label[i-1]);

    int sum=0;
    int cur;
    node *temp;
    for(i=2;i<=V;i++)
    {
        cur = label[i-1];
        temp = graph[cur-1].next;
        while(temp != NULL)
        {
            if(temp->vertexkey == i)
            {
                sum = sum + temp->weight;
                break;
            }
            else
                temp = temp->next;
        }
    }

    printf("Sum = %d", sum);
}
