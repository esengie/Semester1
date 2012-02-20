// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //

#include "stdafx.h"
#include <stdio.h>
int const maxline = 500;
int countInclusions(char source[], char searchfor[]);

int strlen(char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return len;
}
int main( )
{ 
	char s[maxline] = "\0";										
	int length = 0;
	int i = 0;

	printf("this program checks if a line is a palindrome enter a string of letters\n");
	printf ("enter a line\n");
	scanf("%s", s);
	length = strlen(s);
	while (i < length - 1 && s[i] == s[length - 1])
	{	
		i++;
		length--;
	}
	printf("%s", i == length || i == length - 1 && s[i] == s[length] ? "palindrome" : "not a palindrome");
}

int countInclusions( char s[], char sea[])
{
	int i = 0;
	int cnt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{	
		int k = 0;
		for (int j = i; sea[k] != '\0' && sea[k] == s[j]; k++, j++);

		if (k >= 0 && sea[k] == '\0') 
			cnt++;
	}
	return cnt;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
