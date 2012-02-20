
#include "stdio.h"
void shtern(int a, int b, int c, int d, int N);

int main(void)
{	
	int num = 0;
	printf("enter N to print all fractions within the 0-1 segment with denominators not bigger than N\n"); 
	scanf("%d", &num);
	if (!num)
		printf("not zero, you idiot! ah well\n0");
	else 
	{
		int n = 0;
		int m = 1;
		shtern(n, m, m, n, num);
	}
}

void shtern(int a, int b, int c, int d, int N)
{
	if ((b + d > N)||(a + c > N));
	else
	{			
		shtern (a, b, a + c, b + d, N);

		if ((a + c < b + d) && (a + c != 0))
			printf("%d/%d\t", a + c, b + d);

		shtern (a + c, b + d, c, d, N);		
	}
}

//http://ru.wikipedia.org/wiki/%D0%94%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%A8%D1%82%D0%B5%D1%80%D0%BD%D0%B0_%E2%80%94_%D0%91%D1%80%D0%BE%D0%BA%D0%BE
//stolen algorithm, realisation is mine