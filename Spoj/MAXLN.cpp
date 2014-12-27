#include<stdio.h>

using namespace std;

int main()
{
	int cases, i, j;
	double answer, radius;
	long long int temp, temp2;
	float temp1;

	scanf("%d",&cases);


	for(i=0;i<cases;i++)
	{
		scanf("%lf",&radius);
		answer = (double)4*radius*radius;
        answer += 0.25;
        temp = (long long int)answer;
        temp1 = (float)((int)((answer - (double)temp)*100))/(float)100;
        printf("Case %d: %.2lf\n", i+1, (double)temp + (double)temp1);
	}
}
