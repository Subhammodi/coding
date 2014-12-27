#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

typedef struct Tree{
        long int sum;
} tree;

int getMid(int s, int e)
{
    return s + (e -s)/2;
}

void cons(long int *arr, int a, int b, tree *st, int node)
{
    if (a == b)
        st[node].sum = arr[a];
    else
    {
        int mid = getMid(a, b);
        cons(arr, a, mid, st, node*2+1);
        cons(arr, mid+1, b, st, node*2+2);
        st[node].sum = st[2*node+1].sum + st[2*node+2].sum;
    }
}

tree getQuery(tree *st, int a, int b, int i, int j, int index)
{
    if (i <= a && j >= b)
        return st[index];

    int mid = getMid(a, b);

    if(j<=mid)
        return getQuery(st, a, mid, i, j, 2*index+1);
    else if(i>mid)
        return getQuery(st, mid+1, b, i, j, 2*index+2);
    else
    {
        tree p1, p2, p3;

        p1 = getQuery(st, a, mid, i, j, 2*index+1);
        p2 = getQuery(st, mid+1, b, i, j, 2*index+2);
        p3.sum = p1.sum + p2.sum;
        return p3;
    }
}

void updateValueUtil(tree *st, int ss, int se, int i, int diff, int index)
{
    int mid = getMid(ss, se);
    if ( se == ss && se == i )
    {
        st[index].sum = st[index].sum + diff;
        return;
    }
    else if(i <= mid)
		updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
	else
	    updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
	st[index].sum = st[2*index + 1].sum + st[2*index + 2].sum;
}

int main()
{
    int n, i, j, cases, left, right, mode;
    long int answer;

    scanf("%d", &n);
    long int *arr = new long int[n];
    for(i=0;i<n;i++)
        scanf("%ld", &arr[i]);

    long int x = (int)(ceil(log2(n)));
    long int max_size = 2*(int)pow(2, x) - 1;
    tree *st = new tree[max_size];
    cons(arr, 0, n-1, st, 0);

    scanf("%d", &cases);
    for(i=0;i<cases;i++)
    {
        scanf("%d", &mode);
        scanf("%d", &left);
        scanf("%d", &right);
        if(mode == 0)
        {
            if ((left-1) < 0 || (left-1) > n-1)
                printf("Invalid Input\n");
            else
            {
                int diff = right - arr[left-1];
                arr[left-1] = right;
                updateValueUtil(st, 0, n-1, left-1, diff, 0);
            }
        }
        else
        {
            if ((left-1) < 0 || (right-1) > n-1 || (left-1) > (right-1))
                printf("Invalid Input\n");
            else
                printf("%ld\n", getQuery(st, 0, n-1, left-1, right-1, 0).sum);
        }
    }

    return 0;
}
