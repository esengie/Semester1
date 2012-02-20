// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //

#include "stdafx.h"
#include <stdio.h>

long factor (long n);
long factorial (long n);

int main( )
{ 
	long num = 0;
	long boole = 0;
	printf("enter n, and i'll calculate its n! also press \"0\" if you want me to count it recursively or \"1\" for iteratively\n");
	scanf("%ld", &num);
	scanf("%ld", &boole);
	printf("%ld", boole ? factorial(num) : factor(num));
	scanf("%*s");
}


long factor (long n)
{
	if (n == 0)
		return 1;
	else return n * factor (n-1);
}


long factorial (long n)
{
	long ang = 1;
	long i = 1;
	while (i <= n)
	{
		ang *= i;
		++i;
	}
	return ang;
}
	
