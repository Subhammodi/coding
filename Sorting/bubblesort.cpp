#include "header.hpp"

int main()
{
	int n;
	int i, j, k;
	scanf("%d",&n);

	float *arr = new float[n];
	for(i=0;i<n;i++)
		scanf("%f",&arr[i]);

    for(i=0;i<n-1;i++)
        for(j=1;j<(n-i);j++)
		{
			comparisons++;
			if(arr[j]<arr[j-1])
				swap(&arr[j], &arr[j-1]);
		}

    for(i=0;i<n;i++)
        printf("%f\t",arr[i]);
		
    printf("\nNumber of comparisons : %d\n",comparisons);
    printf("Number of swaps : %d\n",swaps);
    return 0;
}
