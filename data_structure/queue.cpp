#include "header.hpp"

typedef struct Queue
{
	int value;
	struct Queue *next;
} queue;

queue *create()
{
	queue *head = new queue;
	head->next = NULL;
	head->value = -1;
	printf("Queue Created with initial queue value as -1.\n");
	return head;
}

void push(queue **tailptr, queue **headptr, int valuee)
{
	if(*tailptr == *headptr && (*tailptr)->value == -1)
	{
		(*tailptr)->value = valuee;
		printf("First element %d inserted.\n",valuee);
	}
	else
	{
		queue *temp = new queue;
		temp->value = valuee;
		temp->next = NULL;
		(*tailptr)->next = temp;
		*tailptr = temp;
		printf("Element %d inserted at the back of queue.\n",valuee);
	}
}

void pop(queue **tailptr, queue **headptr)
{
	if(*tailptr == *headptr && (*tailptr)->value == -1 && (*headptr)->next==NULL)
		printf("No element to pop.\n");
	else
	{
		if(*tailptr == *headptr && (*headptr)->next==NULL)
		{
			printf("Element %d popped.\n",(*headptr)->value);
			(*headptr)->value = -1;
			(*headptr)->next = NULL;
			printf("Queue empty.\n");
		}
		else
		{
			queue *temp = *headptr;
			*headptr = (*headptr)->next;
			printf("Element %d popped.\n",temp->value);
		}
	}
}

void size(queue *head)
{
	int size = 0;

	if(head->value == -1)
		printf("Queue is empty. Size = 0.\n");
	else
	{
		size++;
		while(head->next != NULL)
		{
			head = head->next;
			size++;
		}
		printf("Size = %d.\n",size);
	}
}

void print(queue *head)
{
	if(head->value == -1)
		printf("Queue is empty. No value to print.\n");
	else
	{
		printf("Queue entries are :\n");
		printf("%d\n",head->value);
		while(head->next != NULL)
		{
			head = head->next;
			printf("%d\n",head->value);
		}
	}
}

void deletee(queue **tailptr, queue **headptr)
{
	queue *temp = *headptr;
	if(*tailptr == *headptr && (*tailptr)->value == -1 && (*headptr)->next==NULL)
	{
		*headptr = NULL;
		*tailptr = NULL;
		printf("Queue deleted.\n");
	}
	else
	{
		if((*headptr)->next==NULL)
		{
			*headptr = NULL;
			*tailptr = NULL;
			printf("Queue deleted.\n");
		}
		else
		{
			*headptr = (*headptr)->next;
			delete temp;
			while(*headptr != *tailptr)
			{
				temp = *headptr;
				*headptr = (*headptr)->next;
				delete temp;
			}
            *headptr = NULL;
            *tailptr = NULL;
			printf("Queue deleted.\n");
		}
	}
}

int main()
{
	queue *head = NULL;
	queue *tail = NULL;
	int input;
	int insert;
	while(1)
	{
            print_q();
            scanf("%d",&input);
			switch(input)
			{
				case 1:
					head = create();
					tail = head;
					break;
				case 2:
					if(head == NULL && tail == NULL)
					{
						printf("First create queue.\n");
						break;
					}
					scanf("%d",&insert);
					push(&tail, &head, insert);
					break;
				case 3:
					if(head == NULL)
					{
						printf("First create queue and push some element.\n");
						break;
					}
					pop(&tail, &head);
					break;
				case 4:
					if(head == NULL)
						printf("First create queue and push some element.\n");
					else
					{
						if(head->value == -1)
							printf("No top element to display.\n");
						else
							printf("Top value = %d.\n",head->value);
					}
					break;
				case 5:
					if(head == NULL)
						printf("First create queue and push some element.\n");
					else
					{
						if(head->value == -1)
							printf("No bottom element to display.\n");
						else
							printf("Bottom value = %d.\n",tail->value);
					}
					break;
				case 6:
					if(head == NULL)
						printf("Queue not created.\n");
					else
					{
						if(head->value == -1)
							printf("Yes. Queue is empty.\n");
						else
							printf("No. Queue is not empty.\n");
					}
					break;
				case 7:
					if(head == NULL)
						printf("First create queue and push some element.\n");
					else
						size(head);
					break;
				case 8:
					if(head == NULL)
						printf("First create queue and push some element.\n");
					else
						print(head);
					break;
				case 9:
					if(head == NULL)
						printf("Queue not even present to delete.\n");
					else
						deletee(&tail, &head);
					break;
				case 10:
					break;
			}
			if(input==10)
			{
				printf("EXITING");
				break;
			}
			printf("\n");
	}
	return 0;
}
