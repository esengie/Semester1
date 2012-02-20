// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int fibonacci(int n);



int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	scanf("%d", &i);
	while (i < 1)
	{
		printf ("oh please could you not mess with me like that, now please enter correct number\n");
		scanf("%d", &i);
	}
	i = fibonacci(i);
	printf("%d", i);
	scanf("%d", &i);
		
	return 0;
}

int fibo(int n, int i, int j)
{
	if (n == 3) 
		return (i + j);
	 return fibo (n - 1, i + j, i);
}
int fibonacci (int n)
{
	switch (n)
	{
		case 1:
		case 2:
				return 1;
				break;
			
		default:
			
				return fibo(n, 1, 1); 
				break;
	}
}