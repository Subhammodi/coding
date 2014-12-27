#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
	int packets, i, j, k;
	while(1)
	{
		scanf("%d",&packets);
		if(packets == -1)
			break;
		int *arr = new int[packets];
		j=0;
		for(i=0;i<packets;i++)
		{
			scanf("%d",&arr[i]);
			j += arr[i];
		}
		if((j%packets)!=0)
			printf("-1\n");
		else
		{
            j = j/packets;
            k = 0;
            for(i=0;i<packets;i++)
            {
                k += abs(j-arr[i]);
            }
            printf("%d\n",k/2);
		}
	}

}
