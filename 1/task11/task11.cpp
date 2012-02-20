//expected: 60 minutes  //
//actually:  65 minutes  //


#include <stdio.h>
const int arraylength=300;

void readArray(int arrayA[],  int first, int last);
void printArray(int arrayA[],  int first, int last);
void swap (int * a, int * b);
void quickSort (int arrayA[], int first, int last);

int main( )
{ 
	int arrayA[arraylength];
	int num = 0;
	int cnt = 0;
	int i = 0;
	int number = 0;
	printf("please enter the quantity of elements you want to sort\n");
	scanf("%d", &num);
	printf("now enter the elements\n");
	for (i = 0; i <= num - 1; i++)
		arrayA[i] = 0;
	readArray (arrayA, 0, num - 1);
	quickSort (arrayA, 0, num - 1);
	freopen("output.txt", "wt", stdout);
	printArray (arrayA, 0, num - 1);
}

void readArray (int a[], int first, int last)
{
	int i = 0;
	for (i = first; i <= last; i++)
		scanf("%d ", &a[i]);
}

void printArray (int a[], int first, int last)
{
	int i = 0;
	for (i = first; i <= last; i++)
		printf("%d ", a[i]);
}

void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort (int a[], int first, int last)
{
	if (first < last)
	{	
		int i = first + 1;
		int j = last;
		int mediane = a[(first + last) / 2];
		swap (a + (first+last) / 2, a + first);
		while (i <= j)
		{	
			while (a[i] <= mediane && i <= last )
				i++;
			while (a[j] > mediane && j >= first)
				j--;
			if (i<j)
				swap (a + i, a + j);
		}
		swap(a + j, a + first);
		quickSort (a, first, j - 1);
		quickSort (a, j + 1, last);
	}
}
	