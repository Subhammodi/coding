#include<stdio.h>
#include<stdlib.h>

int main()
{
	int cases, i, j, k, rings;
	int flag;
	scanf("%d",&cases);
	int max, index;
	for(i=0;i<cases;i++)
	{
		flag = true;
		scanf("%d",&rings);

		//int **rad = new int *[rings];
		int **rad = (int **)malloc(rings*sizeof(int *));

		for(j=0;j<rings;j++)
		{
            //rad[j] = new int[2];
            rad[j] = (int *)malloc(2*sizeof(int));
			//rad[j][0] = 9999999-2*j;
			//rad[j][1] = 10000000-2*j;
			scanf("%d",&rad[j][0]);
			scanf("%d",&rad[j][1]);
		}

		max = rad[0][1];
		index = 0;

		for(j=0;j<rings;j++)
			if(rad[j][1] < rad[j][0])
			{
				flag = false;
				goto done;
			}
            else
                if(rad[j][1] > max)
                {
                    max = rad[j][1];
                    index = j;
                }
				/*else
					if(rad[j][1] == max && j != index)
					{
						flag = false;
						goto done;
					}*/

        for(j=0;j<rings;j++)
			if(rad[j][1] >= rad[index][0] && j!=index)
			{
				flag = false;
                goto done;
			}

        done:
        if(flag == false)
            printf("-1\n");
        else
            printf("%d\n",index+1);
	}
}
