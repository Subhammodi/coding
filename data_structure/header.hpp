#ifndef header_hpp
#define header_hpp

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void print_s(void)
{
	printf("1 : Create stack\n");
	printf("2 : Push\n");
	printf("3 : Pop\n");
	printf("4 : Top\n");
	printf("5 : Check if Empty\n");
	printf("6 : Size\n");
	printf("7 : Print Stack\n");
	printf("8 : Delete Stack\n");
	printf("9 : Exit\n");
}

void print_q(void)
{
	printf("1 : Create queue\n");
	printf("2 : Push\n");
	printf("3 : Pop\n");
	printf("4 : Top\n");
	printf("5 : Bottom\n");
	printf("6 : Check if Empty\n");
	printf("7 : Size\n");
	printf("8 : Print Queue\n");
	printf("9 : Delete Queue\n");
	printf("10 : Exit\n");
}

void print_h(void)
{
	printf("1 : Create heap\n");
	printf("2 : Insert value into heap\n");
	printf("3 : Min value of heap\n");
	printf("4 : Decrease key\n");
	printf("5 : Increase key\n");
	printf("6 : Delete a value\n");
	printf("7 : Extract min\n");
	printf("8 : Check if Empty\n");
	printf("9 : Size\n");
	printf("10 : Print Heap\n");
	printf("11 : Heap sort\n");
	printf("12 : Delete heap\n");
	printf("13 : Exit\n");
}

void print_bt(void)
{
	printf("1 : Create\n");
	printf("2 : Insert\n");
	printf("3 : Min value\n");
	printf("4 : Max value\n");
	printf("5 : Search\n");
	printf("6 : Preorder\n");
	printf("7 : Inorder\n");
	printf("8 : Postorder\n");
	printf("9 : Decrease key\n");
	printf("10 : Increase key\n");
	printf("11 : Delete a value\n");
	printf("12 : Check if Empty\n");
	printf("13 : Size\n");
	printf("14 : Max depth\n");
	printf("15 : Delete Btree\n");
	printf("16 : Exit\n");
}

#endif