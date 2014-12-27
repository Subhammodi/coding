#include<stdio.h>
#include<math.h>

int tobinary(int n) {
	int i = 1;
	int answer = 0;
	while(n>0) {
		answer += i*(n%2);
		n /= 2;
		i *= 10;
	}
	return answer;
}

int reverse(int n) {
	int answer = 0;
	while(n>0) {
		answer = answer*10 + (n%2);
		n /= 2;
	}
	return answer;
}

int todecimal(int n) {
	int i = 0;
	int answer = 0;
	while(n>0) {
		answer |= (n%2)<<i;
		n /= 10;
		i++;
	}
	return answer;
}

int swap(int n) {
	int answer = 0;
	return 5;
}

int main()
{
	int dec;
	scanf("%d", &dec);
	printf("Binary = %d\n", tobinary(dec));
	printf("Binary value of reverse = %d\n", reverse(dec));
	printf("Decimal value of reverse = %d\n", todecimal(reverse(dec)));
	printf("palindrome = %d\n", reverse(dec)==tobinary(dec));
	return 0;
}
