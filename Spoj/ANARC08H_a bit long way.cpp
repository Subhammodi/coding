#include<stdio.h>
#include<string.h>

int main()
{
	int no, skip, i, j, k;
	while(1)
	{
		scanf("%d", &no);
		scanf("%d", &skip);
		int temp = no;

		bool *arr = new bool[no+1];
		int *arrr = new int[no];
		memset(arr, true, (no+1)*sizeof(bool));
		for(i=0; i<no; i++)
            arrr[i] = i+1;

		if(no == 0 && skip == 0)
			break;

		int aq = 0;
		for(i=1; i<no; i++)
		{
			for(j=1; j<=skip; j++)
			{
				if(j == skip)
				{
					for(k=aq; k<(temp-1); k++)
						arrr[k] = arrr[k+1];
					temp--;
					arr[arrr[aq]] = false;
					aq = aq - 1;
				}
				aq = aq + 1;
				aq = (aq)%temp;
			}
		}

		printf("%d %d %d\n", no, skip, arrr[0]);
	}

	return 0;
}
