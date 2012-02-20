// start time: 0:50      //
//expected: 20 minutes  //
//actually: 23 minute  //


#include <stdio.h>


int main( )
{ 
	int a = 0;
	int b = 0;
	int i = 0;
	printf("please enter two integers in order (a;b) to find the quotient of a by b\n");
	scanf("%d", &a); 
	scanf("%d", &b); 
	while (a >= b)
	{
		a -= b;
		++i;
	}
	printf("so here it is, quotient of a by b = %d", i);
}
