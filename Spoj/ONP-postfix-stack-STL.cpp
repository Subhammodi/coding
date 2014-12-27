#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include <ctype.h>

using namespace std;

void print(stack<char> node)
{
	stack<char> temp(node);
	char *ans = new char[401];
	temp = node;
	int i=0;
	while(!temp.empty())
	{
		temp.pop();
		i++;
	}
    temp = node;
    ans[i] = '?';

    while(!temp.empty())
	{
	    ans[i-1] = temp.top();
		temp.pop();
		i--;
	}
	i = 0;
	while(ans[i]!='?')
    {
        printf("%c",ans[i]);
        i++;
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
    int cases, i, j;
    scanf("%d",&cases);

    for(i=0;i<cases;i++)
    {
		char *input = new char[401];
		int number = 0;
		scanf("%s",input);
		stack<char> headop;
		stack<char> headans;
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
				{
					headans.push(headop.top());
					headop.pop();
				}
				headop.pop();
			}
			else
			{
				while( pre(headop.top())>=pre(input[j]) )
				{
					headans.push(headop.top());
					headop.pop();
				}
				headop.push(input[j]);
			}
		}

		while(headop.top()!='#')
		{
			headans.push(headop.top());
			headop.pop();
		}

	print(headans);

    printf("\n");
    }
}
