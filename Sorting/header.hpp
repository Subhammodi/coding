#ifndef header_hpp
#define header_hpp

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int comparisons = 0;
int swaps = 0;

void swap(float *, float *);

void swap(float *p, float *q)
{
    float temp;
    temp = *p;
    *p = *q;
    *q = temp;
    swaps++;
}

int digits(int temp)
{
	int d = 0;
	while(temp>0)
	{
		temp = temp/10;
		d++;
	}
	return d;
}

#endif