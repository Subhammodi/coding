#include<stdio.h>

using namespace std;

int main()
{
    int i;
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            break;
        else
            printf("%d\n",(i*(i+1)*(2*i+1))/6);
    }

    return 0;
}
