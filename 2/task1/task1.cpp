
#include "stdafx.h"
#include <stdio.h>

int fib (int number);
int fib1 (int number);

int main(void)
{
	int fibi = 0;
	bool isIterative = 0;
	printf("please enter fibonacci number's number\n");
	scanf ("%d", &fibi);
	printf("and now enter \"0\" - for recursive search or \"1\" for iterative search\n");
	scanf ("%d", &isIterative);
	printf("the #%d fibonacci number is %d\n", fibi, isIterative? fib(fibi) : fib1(fibi));
	scanf("%*s");
}

int fib1 (int n)
{
	return n > 1? fib (n - 1) + fib (n - 2) : 1;
}

int fib (int n)
{	
	int former = 1;
	int j = 1;
	int temp = 0;
	int latter = 1;
	if (n < 2)
		return 1;
	else		
		while (j++ < n)
		{
			temp = former;
			former = latter;
			latter += temp;
		}
		return latter;
}


