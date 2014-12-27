#include<stdio.h>

using namespace std;

int main()
{
    typedef enum raptor{Coding=1, Academia, Eating=4, Sleeping} temp;
    printf("%d\n", Academia);
    temp done = Academia;
    printf("%d\n", done);
}
