#include <stdio.h>
#include <iostream>
#include <math.h>

typedef struct Tree{
        int sum;
} tree;

int getMid(int s, int e)
{
    return s + (e -s)/2;
}

void cons(int *arr, int a, int b, tree *st, int node)
{
    if (a == b)
        st[node].sum = arr[a];
    else
    {
        int mid = getMid(a, b);
        cons(arr, a, mid, st, node*2+1);
        cons(arr, mid+1, b, st, node*2+2);
        st[node].sum = st[2*node+1].sum & st[2*node+2].sum;
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
        p3.sum = p1.sum & p2.sum;
        return p3;
    }
}

int main()
{
	int cases, i, N, K, ans;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d%d", &N, &K);
		int *arr = new int[N];
		for(i=0; i<N; i++)
			scanf("%d", &arr[i]);
		if(K >= N/2)
		{
			ans = arr[0];
			for(i=1; i<N; i++)
				ans = ans & arr[i];

			for(i=0; i<N; i++)
				printf("%d ", ans);
			printf("\n");
		}
		else
		{
			int x = (int)(ceil(log2(N)));
		    int max_size = 2*(int)pow(2, x) - 1;
		    tree *st = new tree[max_size];
		    cons(arr, 0, N-1, st, 0);

			for(i=0; i<K; i++)
				printf("%d ", getQuery(st, 0, N-1, 0, i+K, 0).sum & getQuery(st, 0, N-1, (i-K+N)%N, N-1, 0).sum);
			for(i=K; i<N-K; i++)
				printf("%d ", getQuery(st, 0, N-1, i - K, i + K, 0).sum);
			for(i=N-K; i<N; i++)
				printf("%d ", getQuery(st, 0, N-1, i - K, N-1, 0).sum & getQuery(st, 0, N-1, 0, (i+K)%N, 0).sum);
			printf("\n");
		}
	}
	return 0;
}
