#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include <ctype.h>

using namespace std;

typedef struct Stack
{
	int value;
	struct Stack *next;
} stack;

char pop(stack *node)
{
    char c;
	if(node->next==NULL)
		return '?';
	else
	{
        c = node->next->value;
		node->next = node->next->next;
		return c;
	}
}

void print(stack *node)
{
	stack *temp;
	char *ans = new char[401];
	temp = node;
	int i=0;
	while(temp->next!=NULL)
	{
	    //*(tempp) = temp->next->value
	    //tempp++;
		temp = temp->next;
		i++;
	}
    temp = node;
    ans[i] = '?';

    while(temp->next!=NULL)
	{
	    ans[i-1] = temp->next->value;
		temp = temp->next;
		i--;
	}
	i = 0;
	while(ans[i]!='?')
    {
        printf("%c",ans[i]);
        i++;
    }
}

char top(stack *node)
{
    char c;
	if(node->next==NULL)
		return '?';
	else
		return node->next->value;
}

void push(char c, stack *node)
{
	stack *B = (stack *)malloc(sizeof(stack));
	if (node->next == NULL)
	{
		node->next = B;
		B->value = c;
		B->next =NULL;
	}
	else
	{
		B->next = node->next;
		node->next = B;
		B->value = c;
	}
}

int pre(char h)             //inside priority fuction
{
    switch(h)
	{
		case '#': return 0;
		case '(': return 1;
		case '+': return 2;
		case '-': return 3;
		case '*': return 4;
		case '/': return 5;
		case '^': return 6;
		case ')': return 7;
	}
}

int main()
{

    //stack *temp;// = new stack;
    //temp->value = 3;
    //temp->next = NULL;
    //printf("%d\n",temp->value);
    //printf("%d\n",temp->next);
    //stack *tempp;
    //printf("%d\n",tempp->value);
    //printf("%d\n",temp->value);
    //printf("%d\n",temp->next);
    int cases, i, j;
    scanf("%d",&cases);
    for(i=0;i<cases;i++)
    {
		char *input = new char[401];
		int number = 0;
		scanf("%s",input);
		stack *headop = (stack *)malloc(sizeof(stack));
		headop->next = NULL;
		stack *headans = (stack *)malloc(sizeof(stack));
		headans->next = NULL;
		push('#', headop);
		printf("%c\n",top(headop));

		for(j=0;j<strlen(input);j++)
		{
			if(input[j]=='(')
            {
				push(input[j],headop);
				printf("%c\n",top(headop));
            }
			else if(isalnum(input[j]))
				push(input[j],headans);
			else if(input[j]==')')
			{
				while(top(headop)!='(')
					push(pop(headop),headans);
				char temp = pop(headop);
			}
			else
			{
				while( pre(top(headop))>=pre(input[j]) )
					push(pop(headop),headans);
				push(input[j],headop);
				printf("%c\n",top(headop));
			}
		}

		while(top(headop)!='#')
			push(pop(headop),headans);

	print(headans);

    printf("\n");
    }
}
