#include "stdafx.h"
#include "time.h"
#include <stdlib.h>
const int arraylength = 100;

int main(void)
{
	int a[arraylength][arraylength];
	int i = 0;
	int j = 0;
	int n = 0;
	srand ( time(NULL) );
	printf("enter the width of a table (must be odd number)\n");
	scanf("%d", &n);
	if ((n % 2) != 1)
		printf("duuuuuuude no fair!");
	else
	{
		printf("generated table\n");
		for (i = 0; i < arraylength; i++)
			for ( j = 0; j < arraylength; j++)
				a[i][j] = 0;
		for (i = 0; i < n; i++, printf("\n"))
			for ( j = 0; j < n; j++)
			{
				a[i][j] = rand() % 10;
				printf ("%d ", a[i][j]);
			}					
		int iM = n / 2;
		int jM = n / 2;
		printf ("..meanwhile spirally reading:\n%d ", a[iM][jM]);
		int k=1;
		while (iM < n - 1 && jM < n-1)
		{
			for (j = jM + 1; j <= jM + k; j++)
				printf ("%d ", a[iM][j]);	
			jM+=k;	 
		 
			for (i = iM - 1; i >= iM - k; i--)
				printf ("%d ", a[i][jM]);
			iM-=k;
			
			k++;

			for (j = jM - 1; j >= jM - k; j--)
				printf ("%d ", a[iM][j]);
			jM-=k;

			for (i = iM + 1 ; i <= iM + k; i++)
				printf ("%d ", a[i][jM]);
			iM+=k;
			k++;
		}
		for (j = jM + 1; j <= jM + k-1; j++)
			printf ("%d ", a[iM][j]);
	}
	scanf("%*s");
}

