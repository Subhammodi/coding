#include <stdio.h>
#include<stdlib.h>

static int as = 3;

int main()
{
    //int *arr = (int *)malloc(5*sizeof(int));
    double x = 5.9999;
    int i = x;
double y = 123.5;
    printf("The integer is <test>: %d\n", (int)x+(int)y);
    printf("The float is:   %d\n", i);
}
