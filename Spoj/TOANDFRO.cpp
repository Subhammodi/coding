#include<stdio.h>
#include<cstring>
#include<stdlib.h>

using namespace std;

int main()
{
	int col, i, j;
	while(1)
	{
		scanf("%d",&col);
		if(col==0)
			break;
		char *input = new char[200];
		scanf("%s",input);

		char **output = new char *[strlen(input)/col];
		for(i=0;i<(strlen(input)/col);i++)
            output[i] = new char[col];

        for(i=0;i<(strlen(input)/col);i++)
        {
            for(j=0;j<col;j++)
            {
                if(i%2==0)
                    output[i][j] = input[i*col+j];
                else
                    output[i][col-j-1] = input[i*col+j];
            }
        }

        for(j=0;j<col;j++)
            for(i=0;i<(strlen(input)/col);i++)
                printf("%c",output[i][j]);
		/*char *output[col];
        for(l = 0; l < col; l++)
            output[l] = new char[strlen(input)/col];
		char *temp = new char[3];*/
		printf("\n");
	}
}
