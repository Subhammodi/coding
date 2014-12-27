#include<stdio.h>
#include<iostream>
#include<stdlib.h>

int main()
{
    int i;
    int *temp = new int[5];
    for(i=0; i< 5; i++)
    {
        printf("%d\t", temp[i]);
    }
    printf("\n\n");
    int tempp[5];
    for(i=0; i< 5; i++)
    {
        printf("%d\t", tempp[i]);
    }
    printf("\n\n");
    int *temppp = (int *)malloc(5*sizeof(int));
    for(i=0; i< 5; i++)
    {
        printf("%d\t", temppp[i]);
    }
    return 0;
}
