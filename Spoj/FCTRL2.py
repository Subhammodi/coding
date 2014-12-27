#!/usr/bin/python

def factorial(p):
	if p==0:
		return 1;
	elif p==1:
		return 1;
	else:
		return p*factorial(p-1);

var = input();
for i in range(var):
	a = input();
	print factorial(a);