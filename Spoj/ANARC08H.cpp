#include<stdio.h>
int func(int n,int d)
{
    int i,r=0;
    for(i=2; i<=n; i++)
     r = (r + d) % i;
    return r;
}
int main()
{
    int n,d;
    while(1)
    {
        scanf("%d%d",&n,&d);
        if(n==0&&d==0)
         break;
        else
         printf("%d %d %d\n",n,d,func(n,d)+1);
    }
    return 0;
}