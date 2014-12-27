#include<stdio.h>
#include<math.h>

int main()
{
	int girl, boy;
	int answer;

	while(1)
	{
		scanf("%d",&girl);
		scanf("%d",&boy);
		if(girl == -1 && boy == -1)
			break;
		else
		{
			if(girl<=boy)
            {
                if(boy%(girl+1)==0)
                    printf("%d\n",(boy/(girl+1)));
                else
                    printf("%d\n",(boy/(girl+1)+1));
            }

			else
            {
                if(girl%(boy+1)==0)
                    printf("%d\n",(girl/(boy+1)));
                else
                    printf("%d\n",(girl/(boy+1)+1));
            }
		}
	}

	return 0;
}
