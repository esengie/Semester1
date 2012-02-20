
#include <stdio.h>
#include <iostream>
#include <string>
#include "sadsdas.h"

int main(void)
{
	while(true)
	{
		printf("Enter a double value (or expression): ");
		std::string h;
		std::getline(std::cin, h);
		h += '\0';
		if (parse(h.c_str()))
			printf("OK\n");
		else
			printf("FAIL\n");
	}
		scanf("%*S");
    return 0;
}
