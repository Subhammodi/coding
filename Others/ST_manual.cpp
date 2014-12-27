#include<stdio.h>
#include<iostream>
#include<string.h>

typedef struct Value
{
	int sum;
}value;

int get_mid(int low, int high)
{
	return ((low + high)/2);
}

void cons_st(int *arr, int low, int high, value *st, int node)
{
	if(low == high)
		st[node].sum = arr[low];
	else
	{
		int mid = get_mid(low, high);
		cons_st(arr, low, mid, st, node*2 + 1);
		cons_st(arr, mid+1, high, st, node*2 + 2);
		st[node].sum = st[node*2 + 1].sum + st[node*2 + 2].sum;
	}
}

value query(int *arr, int low, int high, int i, int j, value *st, int node)
{
	if(i <= low && j >= high)
    {
        printf("sddfs\n%d\n", st[0].sum);
		return st[node];
    }
	int mid = get_mid(low, high);
	if(j <= mid)
		return query(arr, low, mid, i, j, st, node*2 + 1);
	else if(i > mid)
		return query(arr, mid+1, high, i, j, st, node*2 + 2);
	else
	{
		value v1, v2, v3;
		v1 = query(arr, low, mid, i, j, st, node*2 + 1);
		v2 = query(arr, mid+1, high, i, j, st, node*2 + 2);
		v3.sum = v1.sum + v2.sum;
		return v3;
	}
}

void update(int *arr, int low, int high, int i, int diff, value *st, int node)
{
	int mid = get_mid(low, high);
	if(low == high && low == i)
		st[node].sum = st[node].sum + diff;
	else if(i <= mid)
	{
		st[node].sum = st[node].sum + diff;
		update(arr, low, mid, i, diff, st, node*2+1);
	}
	else
	{
		st[node].sum = st[node].sum + diff;
		update(arr, mid+1, high, i, diff, st, node*2+2);
	}
}

int main()
{
	int i, no, low, high;
	scanf("%d", &no);

	int *arr = new int[no];
	value *st = new value[2*no-1];

	for(i=0; i<no; i++)
		scanf("%d", &arr[i]);
	cons_st(arr, 0, no-1, st, 0);
	//printf("%d\n\n", st[0].sum);
	char cases[9];
	bool flag = true;
	while(flag)
	{
	    //printf("%d\n\n", st[0].sum);
		scanf("%s", cases);
		//printf("%d\n\n", st[0].sum);
		if(strcmp(cases,"query") == 0)
		{
		    //printf("%d\n\n", st[0].sum);
		    printf("Enter low and high.\n");
			scanf("%d%d", &low, &high);
			//printf("%d\n\n", st[0].sum);
			if(low < 0 || high > no-1 || low > high)
				printf("Wrong input.\n");
			else
				printf("answer = %d\n", query(arr, 0, no-1, low, high, st, 0));
		}
		else if(strcmp(cases,"update") == 0)
		{
		    printf("Enter index and new value.\n");
			scanf("%d%d", &low, &high);
			if(low < 0 || low > no-1 )
				printf("Wrong input.\n");
			else
			{
				int diff = high - arr[low];
				arr[low] = high;
				update(arr, 0, no-1, low, diff, st, 0);
			}
		}
		else if(strcmp(cases,"end") == 0)
        {
            printf("Program ended.\n");
			flag = false;
        }
		else
			printf("No case matched. Re-enter\n");
	}
	printf("%d\n\n", st[0].sum);
	return 0;
}
