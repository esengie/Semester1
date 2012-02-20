#include <cstdio>
#include "sadsdas.h"

int main(void)
{
	while(true)
	{
		printf("Enter a double value (or expression): ");
		char buf[100];
		scanf("%s", buf);

		if (parse(buf))
			printf("OK\n");
		else
			printf("FAIL\n");
	}
    return 0;
}
