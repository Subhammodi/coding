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
	double weight;
	struct Node *next;
} node;

int V;

vertex *createGraph(int);
void insertEdge(int, int, double, vertex *);
void dj(vertex *, double *, int *, char **, int *, int, int);

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

//for undirected graph
void insertEdge(int vertex1, int vertex2, double weight, vertex *graph)
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
		void insert(int, double *, int *);
		int extract_min(double *, int *);
		void decrease(int, double *, int *);
};

void priority_queue::insert(int vertexkey, double *distance, int *pos)
{
	if((current_size + 1) <= max_size)
		arr[current_size] = vertexkey;
	else
		printf("ERROR\n");

	int i = current_size;
	int temp;
	pos[vertexkey-1] = current_size;
	while(i > 0 && (distance[arr[i]-1] > distance[arr[(int)floor((i-1)/2)]-1]))
	{
		temp = pos[arr[i]-1];
		pos[arr[i]-1] = pos[arr[((int)floor((i-1)/2))]-1];
		pos[arr[((int)floor((i-1)/2))]-1] = temp;
		swapp(&arr[i], &arr[((int)floor((i-1)/2))]);
		i = (int)floor((i-1)/2);
	}
	current_size++;
}

int priority_queue::extract_min(double *distance, int *pos)
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
			if( (distance[arr[2*i+1]-1] >= distance[arr[2*i+2]-1]) && (distance[arr[i]-1] < distance[arr[2*i+1]-1]) )
			{
				temp = pos[arr[i]-1];
				pos[arr[i]-1] = pos[arr[2*i+1]-1];
				pos[arr[2*i+1]-1] = temp;
				swapp(&arr[i], &arr[2*i+1]);
				i = 2*i+1;
			}
			else if( (distance[arr[2*i+1]-1] >= distance[arr[2*i+2]-1]) && (distance[arr[i]-1] >= distance[arr[2*i+1]-1]) )
				break;
			else if(distance[arr[i]-1] >= distance[arr[2*i+2]-1])
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
			if(distance[arr[i]-1] >= distance[arr[2*i+1]-1])
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

void priority_queue::decrease(int vertexkey, double *distance, int *pos)
{
	int i = pos[vertexkey - 1];
	int temp;
	if(i >= current_size)
		printf("Invalid input. Element not present in heap.\n");
	else
	{
		while(i > 0 && distance[arr[i]-1] > distance[arr[(int)floor((i-1)/2)]-1])
		{
			temp = pos[arr[i]-1];
			pos[arr[i]-1] = pos[arr[(int)floor((i-1)/2)]-1];
			pos[arr[(int)floor((i-1)/2)]-1] = temp;
			swapp(&arr[i], &arr[(int)floor((i-1)/2)]);
			i = (int)floor((i-1)/2);
		}
	}
}

void dj(vertex *graph, double *distance, int *label, char **flag, int *pos, int V, int start)
{
	priority_queue heap(V);
	node *temp;
	int current, i;

	distance[start-1] = 1;
	heap.insert(start, distance, pos);
	label[start-1] = start;
	flag[start-1] = "G";

	while(heap.current_size != 0)
	{
		current = heap.extract_min(distance, pos);
		if(current == V)
			break;
		else
		{
			flag[current-1] = "B";
			temp = graph[current-1].next;
			while(temp != NULL)
			{
				if(flag[temp->vertexkey - 1] == "W")
				{
					distance[temp->vertexkey-1] = distance[current-1]*temp->weight;
					heap.insert(temp->vertexkey, distance, pos);
					label[temp->vertexkey-1] = current;
					flag[temp->vertexkey-1] = "G";
					temp = temp->next;
				}
				else if(flag[temp->vertexkey - 1] == "G")
				{
					if((distance[current-1]*temp->weight) >= distance[temp->vertexkey-1])
					{
						distance[temp->vertexkey-1] = distance[current-1]*temp->weight;
						heap.decrease(temp->vertexkey, distance, pos);
						label[temp->vertexkey-1] = current;
						flag[temp->vertexkey-1] = "G";
						temp = temp->next;
					}
					else
						temp = temp->next;
				}
				else
					temp = temp->next;
			}
		}
	}
}

int main()
{
	int i, j, E, S, D;
	double prob;
	while(1)
	{
		scanf("%d", &V);
		if(V == 0)
			break;
		scanf("%d", &E);
		vertex *graph = createGraph(V);
		for(i=0; i<E; i++)
		{
			scanf("%d%d%lf", &S, &D, &prob);
			insertEdge(S, D, prob/100, graph);
		}

		double *distance = new double[V];
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

		dj(graph, distance, label, flag, pos, V, 1);

		printf("%lf percent\n", 100*distance[V-1]);
	}
}
