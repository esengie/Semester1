// start time: 17:30      //
//expected: 12 minutes  //
//actually:  14 minutes  //

#include "stdafx.h"
#include <stdio.h>

int main( )
{ 
	char sequence;
	int a = 0;
	bool isIncorrect = 0;
	int i = 0;
	int number = 0;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	printf("enter parentheses\n");
	while ((sequence = getchar()) != EOF && !isIncorrect)
		switch (sequence) 
		{
			case '(': 
				number++; break;
			case ')':
				if (number <= 0) 
				{
					isIncorrect = 1;
					break;
				}
				else number--;
					 break;
		}
	if ( ! isIncorrect && number == 0) 
		printf ("sequence is correct");
	else printf ("sequence is incorrect");
}	