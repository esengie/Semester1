// start time: ...      //
//expected: long long long  //
//actually: long long long  //


#include <stdio.h>
const int arraylength = 5000;

void readArray(int arrayA[],  int first, int last);
void printArray(int arrayA[],  int first, int last);
void swap (int * a, int * b);
void printSums (int arrayA[], int cnt, int number, int max);
//static int max = 0;
int main( )
{ 
	int arrayA[arraylength];
	int num = 0;
	int cnt = 0;
	int i = 0;
	int number = 0;
	freopen ("output.txt", "wt", stdout);
	printf("enter N to print its sums\n");
	scanf("%d", &num);
	
	num--;
	for (i = 0; i <= num; i++)
		arrayA[i] = 1;
	arrayA[num + 1] = num + 1;
	
	printSums(arrayA, number, num, num + 1);

}

void readArray (int a[], int first, int last)
{
	int i = 0;
	for (i = first; i != last + 1; ++i)
		scanf("%d ", &a[i]);
}

void printArray (int a[], int first, int last)
{
	int i = 0;
	for (i = first; i <= last; i++)
		printf("%d ", a[i]);
	printf ("\n");
}

void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
//static int inprint = max;														// two not-really-needed
//static int index = 0;															// variables
void printSums (int a[], int cnt, int n, int max)
{	
	static int inprint = max;														// two not-really-needed
	static int index = 0;
		
	while ((a[n] <= a[n + 1]) && (a[cnt] <= max) && (cnt != n))
	{	
		
		
		
		
		while (a[cnt] == 0)														// this
			cnt++;																// is
		if (a[max - 1] > index)													// my
		{																		// very
			index = a[max - 1];													// crappy 
			inprint = max - index;												// output
		}																		// using
		if (max - 1 - cnt <= inprint)											// two
		{																		// unnecessary
			printArray (a, cnt, max - 1);										// static
		}																		// variables
		inprint--;
		
		
		
		if (a[cnt] == 1)
		{
			a[cnt]--;
			cnt++;		
		}
		else 
			a[cnt]--;		
		a[n]++;

		if ((a[n] >= a[n - 1]) && (a[n + 1] >= a[n]) && (n - cnt) >= 1 )
			{	
				printSums (a, cnt, n - 1, max);
				a [cnt] = 0;
				for (int i = cnt ; i < n; i++)
					a[i] = 1;
			}
	}

	if (cnt == n && a[cnt - 1] == 0 && a[cnt]<=a[n+1] && a[cnt] != 1)			// crappy output
		printArray (a, cnt, max - 1);											// ...again

}


