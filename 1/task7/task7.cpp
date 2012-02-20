// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //

#include "stdafx.h"
#include <stdio.h>
const int arraylength=1000;


int main( )
{ 
	bool arrayA[arraylength];
	int num = 0;
	int cnt = 0;
	int i = 0;
	printf("this is a program which prints all the primes until the entered here integer\n");
	scanf("%d", &num);
	for (i = 0; i <= arraylength - 1; i++)
		arrayA[i] = 1;
	int op = 0;
	while (cnt <= num / 2)
	{	
		i = 2; 
		int j = op;
		while ((!arrayA[i] || j) && i < num)
		{	
			i++;
			if (arrayA[i]) 
				j--;
		}
		cnt = i;
		for (i *= 2; i <= num; i += cnt)
			arrayA[i] = 0;
		op++;
	}
	for (i = 1; i <= num; i++)
	{
		if (arrayA[i])
			printf("%d ", i);
	}
	scanf("%*s");
}

	