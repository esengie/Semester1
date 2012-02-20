// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
//const int lengtharray = 500;//

int main(void)
{
	int a = 0;
	int b = 0;
	int y = 0;
	int temp = 0; 
	int result = 1;
	printf(" enter a and b i'll calculate a^b within log b iterations\n");
	scanf ("%d", &a);
	scanf ("%d", &b);
	//y = b;//
	while (b > 0)
	{
		temp = b % 2;
		b = b / 2; 
		if (temp) 
			result *= a;
		a *= a;
	}
	printf ("%d", result);
	scanf ("%*s");
}

