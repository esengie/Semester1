  //   start time: 15:47									//
 //	 expected: 15 minutes								   //
// actually: 50 minutes because of "#include <stdafx.h>"  // 



#include <stdio.h>


int main( )
{   
	int x = 0;
	int y = 0;
	printf("please enter x, for program to calculate x^4 + x^3 + x^2 + x + 1\n");
	scanf("%d", &x);
	y = x * x;
	printf("x^4 + x^3 + x^2 + x + 1 = %d\n", (y + 1) * (y + x));
}
