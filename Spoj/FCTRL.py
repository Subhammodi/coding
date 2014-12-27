#!/usr/bin/python

count = 0;

def factorial(p,q):
	global count;
	
	if p==0:
		return 1;
	elif p==1:
		return 1;
	else:
		temp = q
		while ((temp%10)==0):
			temp = temp/10;
			count = count + 1;
			
		return factorial(p-1, temp*(p-1));

var = input();
for i in range(var):
	a = input();
	temp1 = factorial(a,a);
	print count;