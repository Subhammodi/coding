#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include <ctype.h>

using namespace std;

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
		op.push_back('#');

		for(j=0;j<strlen(input);j++)
		{
			if(input[j]=='(')
				op.push_back(input[j]);
			else if(isalnum(input[j]))
				ans.push_back(input[j]);
			else if(input[j]==')')
			{
				while(op.back()!='(')
				{
					ans.push_back(op.back());
					op.pop_back();
				}
				op.pop_back();
			}
			else
			{
				while( pre(op.back())>=pre(input[j]) )
				{
					ans.push_back(op.back());
					op.pop_back();
				}
				op.push_back(input[j]);
			}
		}

		while(op.back()!='#')
		{
			ans.push_back(op.back());
			op.pop_back();
		}

	for (vector<char>::iterator it = ans.begin() ; it != ans.end(); ++it)
		printf("%c",*it);

    printf("\n");
    }
}
