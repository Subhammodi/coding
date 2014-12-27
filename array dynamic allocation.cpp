#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arrr = NULL;
    if(arrr == NULL)
            printf("ddfdfsds\n");
    arrr = (int *)realloc(arrr,sizeof(int));
    printf("%d\n",arrr);
	if(arrr == NULL)
            printf("ddfdfsds\n");
    arrr = (int *)realloc(arrr,0);
    printf("%d\n",arrr);
	if(arrr == NULL)
            printf("ddfdfsds123\n");
    arrr = (int *)realloc(arrr,sizeof(int));
    printf("%d\n",arrr);
    free(arrr);
    printf("%d\n",arrr);


    int *arr = new int[5];
    int i;
    for(i=0;i<5;i++)
        scanf("%d",&arr[i]);
    int *temmp = new int[4];
    for(i=0;i<4;i++)
    {
        scanf("%d",&temmp[i]);
        *(arr+5+i) = temmp[i];
    }
    for(i=0;i<9;i++)
        printf("%d\n",arr[i]);
}
