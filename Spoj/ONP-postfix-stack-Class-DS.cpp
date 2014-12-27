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

class boss
{
    private:
        stack *p;
	public:
		boss()
		{
		    p = (stack *)malloc(sizeof(stack));
			p->next = NULL;
		};
		char pop()
		{
			char c;
			if(p->next==NULL)
				return '?';
			else
			{
				c = p->next->value;
				p->next = p->next->next;
				return c;
			}
		}

		void print()
		{
			stack *temp;
			char *ans = new char[401];
			temp = p;
			int i=0;
			while(temp->next!=NULL)
			{
				temp = temp->next;
				i++;
			}
			temp = p;
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

		char top()
		{
			char c;
			if(p->next==NULL)
				return '?';
			else
				return p->next->value;
		}

		void push(char c)
		{
			stack *B = (stack *)malloc(sizeof(stack));
			if (p->next == NULL)
			{
				p->next = B;
				B->value = c;
				B->next =NULL;
			}
			else
			{
				B->next = p->next;
				p->next = B;
				B->value = c;
			}
		}
};

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
    int cases, i, j;
    scanf("%d",&cases);

    for(i=0;i<cases;i++)
    {
		char *input = new char[401];
		vector<char> op, ans;
		int number = 0;
		scanf("%s",input);
		boss headop;
		boss headans;
		headop.push('#');

		for(j=0;j<strlen(input);j++)
		{
			if(input[j]=='(')
				headop.push(input[j]);
			else if(isalnum(input[j]))
                headans.push(input[j]);
			else if(input[j]==')')
			{
				while(headop.top()!='(')
					headans.push(headop.pop());
				char temp = headop.pop();
			}
			else
			{
				while( pre(headop.top())>=pre(input[j]) )
					headans.push(headop.pop());
				headop.push(input[j]);
			}
		}

		while(headop.top()!='#')
			headans.push(headop.pop());

	headans.print();

    printf("\n");
    }
}
