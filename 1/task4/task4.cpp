// start time: 17:30      //
//expected: 60 minutes  //
//actually:  shitload of minutes  //


#include <stdio.h>
const int ARRAYLENGTH=50;

void readArray(int arrayA[],  int first, int last);
void printArray(int arrayA[],  int first, int last);
void swap (int * a, int * b);
void swapArray (int arrayA[], int first, int last);

int main( )
{ 
	int arrayA[ARRAYLENGTH];
	int a = 0;
	int b = 0;
	int i = 0;
	int number = 0;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	printf("please enter two integers to allocate lengths of parts of an array\n");
	scanf("%d %d", &a, &b);
	printf("and now enter %d integers\n", a + b);
	readArray(arrayA, 0, a + b - 1);
	swapArray (arrayA, 0, a + b - 1);
	swapArray (arrayA, 0, b - 1);
	swapArray (arrayA, b, a + b - 1);
	printf("Tada! Swapped it!\n");
	printArray(arrayA, 0, a + b - 1);
	scanf ("%d", &i);
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
	for (i = first; i != last + 1; ++i)
		printf("%d ", a[i]);
}

void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapArray (int a[], int first, int last)
{
	int i = 0;
	for (i = first; i < (first + last + 1) / 2; i++)
	{
		swap(a + i, a + last + first - i);
	}
}
	