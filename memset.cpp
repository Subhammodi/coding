#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    bool *flag = new bool[5];
    for(i=0; i<5; i++)
    {
        if(flag[i] == false)
            printf("%d\n", i);
    }
    memset(flag, 0, 5*sizeof(bool));
    for(i=0; i<5; i++)
    {
        if(flag[i] == false)
            printf("%d\n", i);
    }
    flag[2] = true;
    for(i=0; i<5; i++)
    {
        if(flag[i] == false)
            printf("%d\n", i);
    }
    memset(flag, 0, 5*sizeof(bool));
    for(i=0; i<5; i++)
    {
        if(flag[i] == false)
            printf("%d\n", i);
    }
    return 0;
}
