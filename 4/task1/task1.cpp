#include "stdafx.h"

const int arraylength = 100;

void main(void)
{
	int aim [arraylength];
	int check [arraylength];
	char s[] = "\0";
	char s1[] = "\0";
	int i = 0;
	int j = 0;
	for (; i < arraylength; i++)
		aim[i] = check[i] = 0;

	printf ("enter string\n");
	scanf("%s", s);
	i = 0;
	while (s[i] != '\0')
	{
		aim[s[i] - '0']++;
		i++;
	}
	

	printf ("enter string\n");
	scanf("%s", s1);
	while (s1[j] != '\0')
	{
		check[s1[j] - '0']++;
		j++;
	}
		
	if (j != i)
		printf ("nope can't do");
	else 
	{	
		j = 0;
		while (aim [j] == check[j] && j < arraylength)
			j++;
		printf ((j == arraylength )?"yahoo":"noohoo");
	}
	scanf("%*s");
}

