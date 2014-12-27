#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	long long int answer;
	int i, j;
	int flag;

	while(1)
	{
	    flag = 1;
	    i = 0;
		answer = 1;

	    char *input = new char[20];
	    int *count = new int[21];
	    int *countt = new int[21];
	    int qwe;

	    memset(count, 0, 21*sizeof(int));

		scanf("%s",input);

		if(input[0] == '*')
			break;
        else
        {
            while(input[i] != '\0')
            {
				i++;
                memset(countt, 0, 21*sizeof(int));
                if(input[i-1] != 'N')
                {
                    qwe = i;
                    for(j=2; j<=i; j++)
                    {
                        while( (qwe > 1) && ((qwe%j) == 0) )
                        {
                            countt[j]++;
                            qwe = qwe/j;
                        }
                        if(countt[j] > count[j])
                            count[j] = countt[j];
                    }
                }
            }
			printf("\n%d\n",i);
			for(j=1; j<=i; j++)
			{
					if(j == 13)
							answer *= j;
					else
						answer *= (long long int)pow((float)j, (float)count[j]);
					printf("\n%lld\n",answer);
			}

			for(j=0; j<=20; j++)
				printf("%d.%d\t", j, count[j]);
			printf("\n%lld\n",answer);
			j = 0;
			while(input[j] != '\0')
			{
				if( (input[j] == 'N') && ((answer % (j+1)) == 0) )
					flag = 0;
				j++;
			}

			if(flag == 0)
				printf("-1\n");
			else
				printf("%lld\n",answer);
        }
	}
	return 0;
}
