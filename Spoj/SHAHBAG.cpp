#include<stdio.h>
#include<string.h>

int main()
{
	int people, i, j, group;
	group = 0;
	scanf("%d",&people);

	int *arr = new int[people];
	bool *flag = new bool[20001];
	memset(flag, false, 20001*sizeof(bool));

	for(i=0;i<people;i++)
    {
		scanf("%d", &arr[i]);
		flag[arr[i]] = true;

		if(flag[arr[i]+1] == true && flag[arr[i]-1] == true)
            group--;
        else if(flag[arr[i]+1] == true || flag[arr[i]-1] == true)
            group += 0;
        else
            group++;
        printf("%d\n",group);
    }

    printf("Justice\n");

	return 0;
}
