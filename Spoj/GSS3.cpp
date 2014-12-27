#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

typedef struct Tree{
        long int sum;
        long int ls;
        long int rs;
        long int mx;
} tree;

long int max(long int a, long int b)
{
    return (a<b)?b:a;
}

int getMid(int s, int e)
{
	return s + (e -s)/2;
}

void cons(long int *arr, int a, int b, tree *st, int node)
{
    if (a == b)
    {
        st[node].sum = arr[a];
        st[node].ls = arr[a];
        st[node].rs = arr[a];
        st[node].mx = arr[a];
    }
    else
    {
        int mid = getMid(a, b);
        cons(arr, a, mid, st, node*2+1);
        cons(arr, mid+1, b, st, node*2+2);
        st[node].sum = st[2*node+1].sum + st[2*node+2].sum;
        st[node].ls = max(st[2*node+1].ls, st[2*node+1].sum + st[2*node+2].ls);
        st[node].rs = max(st[2*node+2].rs, st[2*node+2].sum + st[2*node+1].rs);
        st[node].mx = max(max(st[2*node+1].mx, st[2*node+2].mx), st[2*node+1].rs+st[2*node+2].ls);
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
        p3.ls = max(p1.ls , p1.sum+p2.ls);
        p3.rs = max (p2.rs, p2.sum+p1.rs);
        p3.mx = max(max(p1.mx, p2.mx), p1.rs+p2.ls);
        return p3;
    }
}

void update( int node, int pos, int val, int a, int b, tree *st)
{
    if(a > pos || b < pos)
        return;
    if ( a == b && a == pos )
    {
        st[node].sum = val;
        st[node].ls = val;
        st[node].rs = val;
        st[node].mx = val;
        return;
    }

    int mid = getMid(a, b);
    update( node*2 + 1, pos, val, a, mid, st);
    update( node * 2 + 2, pos, val, mid + 1, b, st);
    st[node].sum = st[2*node+1].sum + st[2*node+2].sum;
    st[node].ls = max(st[2*node+1].ls, st[2*node+1].sum + st[2*node+2].ls);
    st[node].rs = max(st[2*node+2].rs, st[2*node+2].sum + st[2*node+1].rs);
    st[node].mx = max(max(st[2*node+1].mx, st[2*node+2].mx), st[2*node+1].rs+st[2*node+2].ls);
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
                update(0, left - 1, right, 0, n-1, st);
            }
        }
        else
        {
            if ((left-1) < 0 || (right-1) > n-1 || (left-1) > (right-1))
                printf("Invalid Input\n");
            else
                printf("%ld\n", getQuery(st, 0, n-1, left-1, right-1, 0).mx);
        }
    }

    return 0;
}
