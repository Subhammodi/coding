#include "header.hpp"

int size;

void insertt(int **arr, int value)
{
	size++;
	int *temp = (int *)realloc(*arr,size*sizeof(int));
    if(temp != NULL)
	{
		*arr = temp;
		(*arr)[size-1] = value;
		printf("Element %d inserted in the heap.\n",value);
	}
	else
		printf("Error re-allocating memory.\n");
	int i = size - 1;
	while(i > 0 && (*arr)[i] < (*arr)[(int)floor((i-1)/2)])
	{
		swap((*arr)[i], (*arr)[(int)floor((i-1)/2)]);
		i = (int)floor((i-1)/2);
	}
}

void create(int **arr)
{
    int n;
    printf("Enter the number of elements :\n");
    scanf("%d",&n);
    int i, input;
	if(n>0)
	{
		size = 0;
		printf("Enter the values :\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&input);
			insertt(arr, input);
		}
	}
	else
		printf("Invalid input. Previous version, if present, exits.\n");
}

void decrease(int *heap)
{
	int value, i, dec;
	printf("Enter the element you want to decrease.\n");
	scanf("%d",&value);
	for(i=0;i<size;i++)
	{
		if(heap[i] == value)
			break;
	}
	if(i == size)
		printf("Invalid input. Element not present in heap.\n");
	else
	{
		printf("Decrement value.\n");
		scanf("%d",&dec);
		heap[i] -= dec;
		while(i > 0 && heap[i] < heap[(int)floor((i-1)/2)])
		{
			swap(heap[i], heap[(int)floor((i-1)/2)]);
			i = (int)floor((i-1)/2);
		}
	}
}

void increase(int *heap)
{
	int value, i, inc;
	printf("Enter the element you want to increase.\n");
	scanf("%d",&value);
	for(i=0;i<size;i++)
	{
		if(heap[i] == value)
			break;
	}
	if(i == size)
		printf("Invalid input. Element not present in heap.\n");
	else
	{
		int min;
		printf("Increment value.\n");
		scanf("%d",&inc);
		heap[i] += inc;
		while((2*i+1) < size)
		{
			if((2*i+2)<size)
			{
				if( (heap[2*i+1] <= heap[2*i+2]) && (heap[i] > heap[2*i+1]) )
				{
					swap(heap[i], heap[2*i+1]);
					i = 2*i+1;
				}
				else if( (heap[2*i+1] <= heap[2*i+2]) && (heap[i] <= heap[2*i+1]) )
					break;
				else if(heap[i] <= heap[2*i+2])
					break;
				else
				{
					swap(heap[i], heap[2*i+2]);
					i = 2*i+2;
				}
			}
			else
			{
				if(heap[i] <= heap[2*i+1])
					break;
				else
				{
					swap(heap[i], heap[2*i+1]);
					i = 2*i+1;
				}
			}
		}
	}
}

void deletee(int **arr)
{
	int value, i;
	printf("Enter the element you want to delete.\n");
	scanf("%d",&value);
	for(i=0;i<size;i++)
	{
		if((*arr)[i] == value)
			break;
	}
	if(i == size)
		printf("Invalid input. Element not present in heap.\n");
	else
	{
		size--;
		(*arr)[i] = (*arr)[size];
		while((2*i+1) < size)
		{
			if((2*i+2)<size)
			{
				if( ((*arr)[2*i+1] <= (*arr)[2*i+2]) && ((*arr)[i] > (*arr)[2*i+1]) )
				{
					swap((*arr)[i], (*arr)[2*i+1]);
					i = 2*i+1;
				}
				else if( ((*arr)[2*i+1] <= (*arr)[2*i+2]) && ((*arr)[i] <= (*arr)[2*i+1]) )
					break;
				else if((*arr)[i] <= (*arr)[2*i+2])
					break;
				else
				{
					swap((*arr)[i], (*arr)[2*i+2]);
					i = 2*i+2;
				}
			}
			else
			{
				if((*arr)[i] <= (*arr)[2*i+1])
					break;
				else
				{
					swap((*arr)[i], (*arr)[2*i+1]);
					i = 2*i+1;
				}
			}
		}
		int j;
		int *temp = (int *)realloc(*arr,size*sizeof(int));
		*arr = temp;
		if(size == 0)
            printf("Only element %d is deleted from the heap. Heap empty. Recreate it.\n",value);
        else
            printf("Element %d deleted from the heap.\n",value);
	}
}

void extract_min(int **arr, bool flag)
{
	int i = 0;
	if(size == 1 && flag == true)
		printf("Min element %d was the only element and is deleted from the heap. Heap empty. Recreate it.\n",(*arr)[i]);
	else if(size > 1 && flag == true)
		printf("Min element %d deleted from the heap.\n",(*arr)[i]);
	else
		{}
	size--;
	(*arr)[i] = (*arr)[size];
	while((2*i+1) < size)
	{
		if((2*i+2)<size)
		{
			if( ((*arr)[2*i+1] <= (*arr)[2*i+2]) && ((*arr)[i] > (*arr)[2*i+1]) )
			{
				swap((*arr)[i], (*arr)[2*i+1]);
				i = 2*i+1;
			}
			else if( ((*arr)[2*i+1] <= (*arr)[2*i+2]) && ((*arr)[i] <= (*arr)[2*i+1]) )
				break;
			else if((*arr)[i] <= (*arr)[2*i+2])
				break;
			else
			{
				swap((*arr)[i], (*arr)[2*i+2]);
				i = 2*i+2;
			}
		}
		else
		{
			if((*arr)[i] <= (*arr)[2*i+1])
				break;
			else
			{
				swap((*arr)[i], (*arr)[2*i+1]);
				i = 2*i+1;
			}
		}
	}
	int *temp = (int *)realloc(*arr,size*sizeof(int));
	*arr = temp;
}

int main()
{
	int input, insert;
	int *heap = NULL;
	while(1)
	{
            print_h();
            scanf("%d",&input);
			switch(input)
			{
				case 1:
                    create(&heap);
					break;
				case 2:
					if(heap == NULL)
					{
						printf("First create heap.\n");
						break;
					}
					scanf("%d",&insert);
					insertt(&heap, insert);
					break;
				case 3:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						printf("Min value = %d.\n",heap[0]);
					break;
				case 4:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						decrease(heap);
					break;
				case 5:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						increase(heap);
					break;
				case 6:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						deletee(&heap);
					break;
				case 7:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						extract_min(&heap, true);
					break;
				case 8:
					if(heap == NULL)
						printf("Heap not created or is empty. Create it.\n");
					else
						printf("No. Heap is not empty.\n");
					break;
				case 9:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
						printf("Size = %d.\n",size);
					break;
				case 10:
					if(heap == NULL)
						printf("First create heap and then insert elements into it to print them.\n");
					else
					{
						int i;
						printf("Heap entries are :\n");
						for(i=0;i<size;i++)
							printf("%d\n",heap[i]);
					}
					break;
				case 11:
					if(heap == NULL)
						printf("First create heap and then insert elements into it.\n");
					else
					{
						int i;
						printf("Sorted order of elements in heap :\n");
						int temp = size;
						for(i=0;i<temp;i++)
						{
							printf("%d\t",heap[0]);
							extract_min(&heap, false);
						}
						printf("\nHeap empty. Recreate it for further use.\n");
					}
					break;
				case 12:
					if(heap == NULL)
						printf("Heap not even present to delete.\n");
					else
					{
						size = 0;
						heap = (int *)realloc(heap, size*sizeof(int));
						free(heap);
						printf("Heap deleted. Recreate it to use further.\n");
					}
					break;
				case 13:
					break;
			}
			if(input==13)
			{
				printf("EXITING");
				break;
			}
			printf("\n");
	}
	return 0;
}
