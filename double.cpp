#include<iostream>
#include<stdio.h>

int main()
{
    double temp;
    int te;
    while(1)
    {
        scanf("%lf", &temp);
        te = (int)temp;
        printf("%d\n", te);
        te = temp;
        printf("%d\n", te);
        printf("%lf\n", temp);
    }
    return 0;
}
