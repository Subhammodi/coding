#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
int main() {
	char *temp = NULL;
	int cases, count;
	char temp_input;
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
		printf("%s\t%d\n", temp, strlen(temp));
	}
	return 0;
}