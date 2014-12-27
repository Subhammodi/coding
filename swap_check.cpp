#include<stdio.h>

void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a =3, b=4;
    swap1(a, b);
    printf("%d\t%d\n\n", a, b);
    swap2(a, b);
    printf("%d\t%d\n\n", a, b);
    swap3(&a, &b);
    printf("%d\t%d\n\n", a, b);
    return 0;
}
