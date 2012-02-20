// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //

#include "stdafx.h"
#include <stdio.h>

long power (int base, int power);


int main( )
{ 
	int n = 0;
	int a = 0;
	printf("enter a and n, and i'll calculate a^n\n");
	scanf("%d", &a);
	scanf("%d", &n);
	printf("%ld", power(a,n));
	scanf("%*s");
}





long power (int a, int n)
{
	long ang = 1;
	while (n > 0)
	{ 
		ang *= (long)a;
		--n;
	}
	return ang;
}
	
