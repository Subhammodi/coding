#include "header.hpp"

int main()
{
	int i, n;

	scanf("%d",&n);
	int *arr = new int[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int max;
	max = arr[0];
	for(i=1;i<n;i++)
		if(arr[i]>max)
			max = arr[i];

	int *aarr = new int[n];
	int count[max+1];
	memset(count, 0, sizeof(count));

    for(i=0;i<n;i++)
		count[arr[i]]++;
	for(i=1;i<(max+1);i++)
        count[i] = count[i] + count[i-1];

	for(i=(n-1);i>=0;i--)
		aarr[(count[arr[i]]--)-1] = arr[i];

    for(i=0;i<n;i++)
	{
		arr[i] = aarr[i];
        printf("%d\t",arr[i]);
	}

    return 0;
}
