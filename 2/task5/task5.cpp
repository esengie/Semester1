// start time: 17:30      //
//expected: 180 minutes  //
//actually:  60 minutes  //


#include <stdio.h>
const int arraylength=5000;

void readArray(int arrayA[],  int first, int last);
void printArray(int arrayA[],  int first, int last);
void swap (int * a, int * b);
void heapSort (int arrayA[], int first, int last);
void pushDown(int arrayA[], int first, int last);

int main( )
{ 
	int arrayA[arraylength];
	int num = 0;
	int zero = 1;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	printf("this is da Heapsort, fear and tremble!!! enter N here\n");
	scanf("%d", &num);
	printf("enter %d elements\n", num);
	readArray(arrayA, zero, num);
	heapSort(arrayA, zero, num);
	printArray (arrayA, zero, num);
}

void readArray (int a[], int first, int last)
{
	for (int i = first; i <= last; i++)
		scanf("%d ", &a[i]);
}

void printArray (int a[], int first, int last)
{
	for (int i = first; i <= last; i++)
		printf("%d ", a[i]);
}

void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void pushDown (int a[], int first, int last)
{
	int i = first;
	while (i <= last / 2)
	{
		if (i * 2 == last)
		{
			if (a[i] > a[last])
				swap (&a[i], &a[last]);
			i = last;
		}
		else
		{
			if ((a[i] > a[2 * i]) && (a[2 * i] <= a[2 * i + 1]))
			{
				swap (&a[i], &a[2 * i]);
				i *= 2;
			}
			else 
				if ((a[i] > a[2 * i + 1]) && (a[2 * i + 1] < a[2 * i]))
				{
					swap (&a[i], &a[2 * i + 1]);
					i = i * 2 + 1;
				}
				else
					i = last;
		}
	}
}

void heapSort (int a[], int first, int last)
{	
	int i = last / 2;
	for (i; i >= first; i--)
		pushDown(a, i, last); 
	for (i = last; i > first; i--)
	{
		swap (&a[i], &a[first]);
		pushDown (a, first, i - 1);
	}
}

	