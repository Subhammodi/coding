#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int i;

    while(1)
    {
        scanf("%d",&i);

        if(i==42)
            break;
        else
            printf("%d\n",i);
    }

    return 0;
}
