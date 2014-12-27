#include "header.hpp"

int main()
{
	int n;
	int i, j, k;
	float max;
	scanf("%d",&n);

	float *arr = new float[n];
	for(i=0;i<n;i++)
		scanf("%f",&arr[i]);

    for(i=0;i<n-1;i++)
    {
        max = arr[0];
        k = 0;
        for(j=1;j<(n-i);j++)
		{
		    comparisons++;
            if(arr[j]>max)
			{
				max = arr[j];
				k = j;
			}
		}
		if(k!=(n-i-1) && arr[k]!=arr[n-i-1])
            swap(&arr[k], &arr[n-i-1]);
    }

    for(i=0;i<n;i++)
        printf("%f\t",arr[i]);

    printf("\nNumber of comparisons : %d\n",comparisons);
    printf("Number of swaps : %d\n",swaps);
    return 0;
}
