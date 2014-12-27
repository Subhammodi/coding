#include<stdio.h>
#include<ctype.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    /*enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
    colors_t mycolor;
    scanf("%d",&mycolor);
    if (mycolor == green)
        mycolor = red;
    printf("%d",mycolor);
    printf("%d",sizeof(mycolor));
	char *c;
	scanf("%s",c);
	printf("%s\n",c);*/
	//int fr = Diamonds;
	//printf("%d\n",fr);
	string as;
	//char *as = new char[4];
	cin >> as;
	cout << as << endl;
	enum colors_t {black, blue, green, as};
	/*printf("%d\n",sizeof(as));
	switch(as)
	{
        case 0:
            printf("cat\n");
            break;
        case 1:
            printf("rat\n");
            break;
        case 2:
            printf("bat\n");
            break;
        default:
            printf("none of these\n");
	}*/
/*	if(c<95)
        printf("%c",c+32);
    else
        printf("%c",c-32);*/
        return 0;
}
