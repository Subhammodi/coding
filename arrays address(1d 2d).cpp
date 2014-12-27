#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main()
{
    int i, n = 5;
    int mix[n][n];
    memset(mix, 0, sizeof(mix));
    int **smo = new int*[n];

    for(i=0; i<5; i++)
    {
        smo[i] = new int[n];
        memset(smo[i], 0, n*sizeof(int));
    }

    for(i=0; i<5; i++)
    {
        printf("%d\n", *(smo[0] + i));
        printf("%d\n", *(mix[i]+2));
    }
    /*cout << n*sizeof(int) << endl;
    cout << sizeof(smo) << endl;
    cout << mix << endl << smo << mix+n << endl << smo+n << endl;*/
    return 0;
}
