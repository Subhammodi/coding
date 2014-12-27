#include "header.hpp"

typedef struct Stack
{
	int value;
	struct Stack *next;
} stack;

stack *create()
{
	stack *head = new stack;
	head->next = NULL;
	head->value = -1;
	printf("Stack Created with initial stack value as -1.\n");
	return head;
}

void push(stack **headptr, int valuee)
{
	if((*headptr)->next==NULL && (*headptr)->value==-1)
    {
		(*headptr)->value = valuee;
		printf("First element %d inserted.\n",valuee);
    }
	else
	{
		stack *temp = new stack;
		temp->value = valuee;
		temp->next = *headptr;
		*headptr = temp;
		printf("Element %d inserted.\n",valuee);
	}
}

void pop(stack **headptr)
{
	if((*headptr)->next==NULL && (*headptr)->value==-1)
		printf("No element to pop.\n");
	else
	{
		if((*headptr)->next==NULL)
		{
			printf("Element %d popped.\n",(*headptr)->value);
			(*headptr)->value = -1;
			(*headptr)->next = NULL;
			printf("Stack empty\n");
		}
		else
		{
			stack *temp = *headptr;
			*headptr = (*headptr)->next;
			printf("Element %d popped.\n",temp->value);
		}
	}
}

void size(stack *head)
{
	int size = 0;

	if(head->value == -1)
		printf("Stack is empty. Size = 0.\n");
	else
	{
		size++;
		while(head->next != NULL)
		{
			head = head->next;
			size++;
		}
		printf("Size = %d.",size);
	}
}

void print(stack *head)
{
	if(head->value == -1)
		printf("Stack is empty. No value to print.\n");
	else
	{
		printf("Stack entries are :\n");
		printf("%d\n",head->value);
		while(head->next != NULL)
		{
			head = head->next;
			printf("%d\n",head->value);
		}
	}
}

void deletee(stack **headptr)
{
	stack *temp = *headptr;
	if((*headptr)->value == -1)
	{
		*headptr = NULL;
		printf("Stack deleted.\n");
	}
	else
	{
		if((*headptr)->next==NULL)
		{
			*headptr = NULL;
			printf("Stack deleted.\n");
		}
		else
		{
			*headptr = (*headptr)->next;
			while(*headptr != NULL)
			{
				delete temp;
				temp = *headptr;
				*headptr = (*headptr)->next;
			}
			printf("Stack deleted.\n");
		}
	}
}

int main()
{
	stack *head = NULL;
	int input;
	int insert;
	while(1)
	{
            print_s();
            scanf("%d",&input);
			switch(input)
			{
				case 1:
					head = create();
					break;
				case 2:
					if(head == NULL)
					{
						printf("First create stack.\n");
						break;
					}
					scanf("%d",&insert);
					push(&head, insert);
					break;
				case 3:
					if(head == NULL)
					{
						printf("First create stack and push some element.\n");
						break;
					}
					pop(&head);
					break;
				case 4:
					if(head == NULL)
						printf("First create stack and push some element.\n");
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
						printf("Stack not created.\n");
					else
					{
						if(head->value == -1)
							printf("Yes. Stack is empty.\n");
						else
							printf("No. Stack is not empty.\n");
					}
					break;
				case 6:
					if(head == NULL)
						printf("First create stack and push some element.\n");
					else
						size(head);
					break;
				case 7:
					if(head == NULL)
						printf("First create stack and push some element.\n");
					else
						print(head);
					break;
				case 8:
					if(head == NULL)
						printf("Stack not even present to delete.\n");
					else
						deletee(&head);
					break;
				case 9:
					break;
			}
			if(input==9)
			{
				printf("EXITING");
				break;
			}
			printf("\n");
	}
	return 0;
}
