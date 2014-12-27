#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<math.h>
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
		}
		int pop()
		{
			int c;
			if(p->next==NULL)
				return '?';
			else
			{
				c = p->next->value;
				p->next = p->next->next;
				return c;
			}
		}
		int top()
		{
			int c;
			if(p->next==NULL)
				return '?';
			else
				return p->next->value;
		}
		void push(int c)
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

int main()
{
    int cases, i, j;
    scanf("%d",&cases);

    for(i=0;i<cases;i++)
    {
		char *input = new char[401];
		int number = 0;
		scanf("%s",input);
		boss headans;
		headans.push('#');
		int a, b;
		int insert;

		for(j=0;j<strlen(input);j++)
		{
			if(isdigit(input[j]))
			{
				insert = input[j] - '0';
                headans.push(insert);
			}
			else
			{
				a = headans.pop();
				b = headans.pop();
				if (input[j]=='-')
                    headans.push(b-a);
                else if (input[j]=='+')
                    headans.push(a+b);
                else if (input[j]=='*')
                    headans.push(a*b);
                else if (input[j]=='/')
                    headans.push(b/a);
                else
                    headans.push(pow(b,a));
			}
		}
	printf("%d\n",headans.top());
    printf("\n");
    }
}
