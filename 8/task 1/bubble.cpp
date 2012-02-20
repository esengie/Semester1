# include "bubble.h"


void swap (int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int* bubble::sort (int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap (a[i], a[j]);
		}
	}
	return a;
}

