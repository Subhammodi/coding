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
	int i, j, cases, price, S, D, L, E;

	scanf("%d", &cases);
	for(i=0; i<cases; i++)
	{
		scanf("%d%d%d", &price, &V, &E);
		vertex *graph = createGraph(V);
		for(j=0;j<E;j++)
		{
			scanf("%d%d%d", &S, &D, &L);
			insertEdge(S, D, L*price, graph);
		}
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

		prims(graph, distance, label, flag, pos, V, 1);

		unsigned int sum=0;
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

		printf("%u", sum);
	}
}
