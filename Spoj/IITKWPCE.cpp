#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int i, j, k, l, cases, answer;
	string input, input1;
	scanf("%d",&cases);
	bool flag;

	for(i=0; i<cases; i++)
	{
		answer = 0;
		cin >> input;

		for(j=input.length(); j>0; j--)
		{
			flag = false;
            l = input.length() - j;
			for(k=0; k<=l; k++)
			{
				input1 = input.substr(k, j);
				reverse(input1.begin(), input1.end());
				if((input.substr(k, j)).compare(input1) == 0)
				{
					flag = true;
					answer++;
					input = input.substr(0,k) + input.substr(k+j, input.length() - (k+j));
					l = input.length() - j;
					k = -1;
				}
			}
			if(flag == true)
				j = input.length()+1;
		}
		printf("%d\n", answer);
	}
	return 0;
}
