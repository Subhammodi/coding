#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int l, i;
char *temp;
char temp_input;

int max(int p, int q) {
	return ((p>=q) ? p:q);
}

int func(char *&pre, int start, int end) {
	l = 0;
	if(pre[start] == 'l')
		return 0;
	else {
		for(i=(start+1); i<=end; i++) {
			if(pre[i] == 'l')
				l++;
			if((i-start-l) == (l-1))
				break;
		}
    return 1 + max(func(pre, start+1, i), func(pre, i+1, end));
    }
}

int main()
{
	int cases, count;
	scanf("%d", &cases);
	temp_input = getchar();
	while(cases--) {
		count = 0;
		temp = NULL;
		while(1) {
			temp_input = getchar();
			if(temp_input == '\n')
				break;
			else {
				count++;
				temp = (char *)realloc(temp, count*sizeof(char));
				temp[count-1] = temp_input;
			}
		}
		printf("%d\n", func(temp, 0, strlen(temp)-1));
	}
	return 0;
}
