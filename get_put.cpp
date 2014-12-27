#include<stdio.h>

int main()
{
    char t;
    int ii;
    char *temp = new char[10];
    gets(temp);
    int i = 0;
    while(1)
    {
        if(i == 6)
            break;
        temp[i] = getchar();
        putchar(temp[i]);
        //putchar('\n');
        i++;
    }
    puts("output");
    puts(temp);
    puts("kh");
    scanf("%d",&ii);
    printf("%d",ii);
}
