// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //

#include "stdafx.h"
#include <stdio.h>
int const maxline = 500;
int countInclusions(char source[], char searchfor[]);

int main( )
{ 
	char s[maxline] = "\0";										
	char s1[maxline] = "\0";								
	char c = '\0';
	int number = 0;
	int i = 0;

	printf("this program counts the number of inclusions of one string into another, enter a string of letters in which to search\n");
	scanf("%s", s);
	printf("%s", s1);
	scanf("%s", s1);
	printf("%d\n", countInclusions (s, s1));

}

int countInclusions( char s[], char sea[])
{
	int i = 0;
	int cnt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{	
		int k = 0;
		for (int j = i; sea[k] != '\0' && sea[k] == s[j]; k++, j++)
		{
			
		}
		if (k >= 0 && sea[k] == '\0') 
				cnt++;
	}
	return cnt;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
