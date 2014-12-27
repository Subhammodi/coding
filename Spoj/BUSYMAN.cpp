#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	int cases, i, j, act, answer, temp1, temp2;
	scanf("%d",&cases);

	for(i=0; i<cases; i++)
	{
		answer = 0;
		scanf("%d", &act);
		multimap<int, int> mymap;

		for(j=0; j<act; j++)
		{
			scanf("%d",&temp1);
			scanf("%d",&temp2);
			mymap.insert(make_pair(temp2, temp1));;
		}

		multimap<int,int>::iterator it = mymap.begin();

		if(mymap.size() != 0)
		{
			int end_time = it->first;
			it++;
			answer++;

			for(;it != mymap.end(); it++)
				if(it->second >= end_time)
				{
					end_time = it->first;
					answer++;
				}
		}
		printf("%d\n",answer);
	}
	return 0;
}
