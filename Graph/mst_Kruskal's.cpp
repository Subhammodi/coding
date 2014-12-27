#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>

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
multimap<int, pair<int, int> > kruskal(vertex *, multimap<int, pair<int, int> >, int *, int);

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

multimap<int, pair<int, int> > sort(vertex *graph)
{
	int i;
	bool check = true;
	node *temp;
	multimap<int, pair<int, int> > sorted;
	multimap<int, pair<int, int> >::iterator it;
	pair<int, int> tempp;
	for(i=1; i<=V; i++)
	{
		temp = graph[i-1].next;
		while(temp!=NULL)
		{
			if(sorted.find(temp->weight) == sorted.end())
			{
				tempp = make_pair(graph[i-1].vertexnumber, temp->vertexkey);
				sorted.insert(pair<int, pair<int, int> >(temp->weight, tempp));
				temp = temp->next;
			}
			else
			{
				it = sorted.find(temp->weight);
				while((*it).first == temp->weight)
				{
					if((((*it).second).first == temp->vertexkey) && (((*it).second).second == graph[i-1].vertexnumber))
					{
						check = false;
						break;
					}
					else
						it++;
				}

				if(check == true)
				{
					tempp = make_pair(graph[i-1].vertexnumber, temp->vertexkey);
					sorted.insert(pair<int, pair<int, int> >(temp->weight, tempp));
					temp = temp->next;
				}
				else
					temp = temp->next;
			}
			check = true;
		}
	}

	return sorted;
}

int find(int *parent, int vertexkey)
{
	if(parent[vertexkey-1] == vertexkey)
		return vertexkey;
	else
		return find(parent, parent[vertexkey-1]);
}

bool same_set(int first, int second, int *parent)
{
	if(find(parent, first) == find(parent, second))
		return true;
	else
		return false;
}

void unionn(int first, int second, int *parent)
{
	int temp = find(parent, second);
	parent[temp - 1] = first;
}

multimap<int, pair<int, int> > kruskal(vertex *graph, multimap<int, pair<int, int> > sorted, int *parent, int V)
{
	int i;
	multimap<int, pair<int, int> >::iterator it;
	multimap<int, pair<int, int> > sorted_temp;
	pair<int, int> tempp;
	for (it = sorted.begin(); it != sorted.end(); it++)
	{
		if(!same_set((it->second).first, (it->second).second, parent) )
		{
		    tempp = make_pair((it->second).first, (it->second).second);
            sorted_temp.insert(pair<int, pair<int, int> >(it->first, tempp));
			unionn( (it->second).first, (it->second).second, parent );
		}
		else
			continue;
	}
	return sorted_temp;
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

	multimap<int, pair<int, int> > sorted = sort(graph);
	multimap<int, pair<int, int> >::iterator it;

	/*printf("W\tS\tD\n\n");
	for(it = sorted.begin(); it!= sorted.end(); it++)
		printf("%d\t%d\t%d\n", it->first, (it->second).first, (it->second).second);*/

	int *parent = new int[V];
	for(i=1;i<=V;i++)
		parent[i-1] = i;

	printf("Calculating MST.\n");
	multimap<int, pair<int, int> > sorted_final;
	sorted_final =  kruskal(graph, sorted, parent, V);

	int sum=0;
    for(it = sorted_final.begin(); it!= sorted_final.end(); it++)
    	sum += it->first;

    printf("Sum = %d\n", sum);

    printf("W\tS\tD\n\n");
	for(it = sorted_final.begin(); it!= sorted_final.end(); it++)
		printf("%d\t%d\t%d\n", it->first, (it->second).first, (it->second).second);
}
