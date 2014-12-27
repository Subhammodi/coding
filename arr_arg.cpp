#include<stdio.h>
#include<string.h>

using namespace std;

void print(int p[][3], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
}

int main()
{
    int i, j;

    int (*pp)[3];
    /*for(i=0;i<3;i++)
    {
        pp = i;
        printf("%d\t",pp[i]);
    }
    printf("\n");*/


	int p[3][3];
	for(i=0;i<3;i++)
	{
		//p[i] = new int[4];
		for(j=0;j<3;j++)
			p[i][j] = i+j;
	}

    print(p, 3);
    memset(p, -1, sizeof(p[0][0])*3*3);
    print(p, 3);
    int **arr = new int *[3];
    for(i=0;i<3;i++)
    {
        arr[i] = new int[3];
        for(j=0;j<3;j++)
            arr[i][j] = i+j;
    }
    //int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//    print(arr);
}
