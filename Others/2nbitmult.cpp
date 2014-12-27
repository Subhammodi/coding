#include <stdio.h>
#include <iostream>
#include <math.h>

int power(int no, int exp)
{
    int ans = 1, i;
    for(i=0; i<exp; i++)
        ans *= no;
    return ans;
}

int digits(int temp)
{
    if(temp == 0)
        return 1;
    else
    {
        int d = 0;
        while(temp>0)
        {
            temp = temp/10;
            d++;
        }
        return d;
    }
}

int number(int temp, int filter)
{
	int tempp = temp%power(10, filter);
	tempp = tempp/power(10, filter-1);
	return tempp;
}

int tobinary(int no)
{
	int ans = 0, i=0;

	while(no > 0)
	{
		ans += (no%2)*power(10, i++);
		no = no/2;
	}
	return ans;
}

int todecimal(int no)
{
	int i, ans = 0, len;
	len = digits(no);

	for(i=0; i<len; i++)
		ans += number(no, i+1)*power(2, i);
	return ans;
}

int add(int binary1, int binary2)
{
	int answer = 0, i = 0, remain = 0;;

	while(binary1!=0||binary2!=0)
	{
		answer +=  power(10, i)*((binary1 %10 + binary2 %10 + remain ) % 2);
		remain = (binary1 %10 + binary2 %10 + remain ) / 2;
		binary1 = binary1/10;
		binary2 = binary2/10;
		i++;
    }

    if(remain!=0)
    	answer += power(10, i)*remain;

    return answer;

}

int final(int binary1, int binary2)
{
	int answer, A, B, C, D, ac, bd, abcd, left, mid, right, temp1, temp2, add1 = 0, add2 = 0, i;

	if(digits(binary1) == 1 || digits(binary2) == 1)
		return binary1*binary2;
	else
	{
		A = binary1 / power(10, digits(binary1)/2);
		B = binary1 % power(10, digits(binary1)/2);
		C = binary2 / power(10, digits(binary2)/2);
		D = binary2 % power(10, digits(binary2)/2);
		
		add1 = digits(binary1)/2 - digits(A);
		add2 = digits(binary2)/2 - digits(C);
		A = tobinary(todecimal(A) << add1);
		C = tobinary(todecimal(C) << add2);
		ac = tobinary(todecimal(final(A, C)) >> (add1 + add2));

		add1 = digits(binary1)/2 - digits(B);
		add2 = digits(binary2)/2 - digits(D);
		B = tobinary(todecimal(B) << add1);
		D = tobinary(todecimal(D) << add2);
		bd = tobinary(todecimal(final(B, D)) >> (add1 + add2));

		add1 = 0;
		add2 = 0;
		temp1 = add(A, B);
		temp2 = add(C, D);
		for(i=0;;i++)
		{
			if(digits(temp1) == power(2,i))
				break;
			else if(digits(temp1) < power(2,i))
			{
				add1 = power(2,i) - digits(temp1);
				break;
			}
			else
				continue;
		}
		for(i=0;;i++)
		{
			if(digits(temp2) == power(2,i))
				break;
			else if(digits(temp2) < power(2,i))
			{
				add2 = power(2,i) - digits(temp2);
				break;
			}
			else
				continue;
		}
		if((digits(temp1) + add1) != (digits(temp2) + add2))
		{
			if((digits(temp1) + add1) > (digits(temp2) + add2))
				add2 = digits(temp1) + add1 - digits(temp2);
			else
				add1 = digits(temp2) + add2 - digits(temp1);
		}
		temp1 = tobinary(todecimal(temp1) << add1);
		temp2 = tobinary(todecimal(temp2) << add2);
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", binary1, temp1, add1, binary2, temp2, add2);
		abcd = tobinary(todecimal(final(temp1, temp2)) >> (add1 + add2));
		left = todecimal(ac) << digits(binary1);
		if((todecimal(abcd) - todecimal(ac) - todecimal(bd)) >= 0)
            mid = (todecimal(abcd) - todecimal(ac) - todecimal(bd)) << (digits(binary1)/2);
        else
            mid = 0;
		right = todecimal(bd);
		answer = left + mid + right;
		//printf("%d\n", answer);
		return tobinary(answer);
	}
}

int main()
{
	int no1, no2;
	scanf("%d%d", &no1, &no2);
	int no1b = tobinary(no1), no2b = tobinary(no2);

	printf("Binary Answer = %d.\n", final(no1b, no2b));
	printf("Decimal Answer = %d.\n", todecimal(final(no1b, no2b)));


	return 0;
}
