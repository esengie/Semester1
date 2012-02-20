#include "Expell.h"

static int drunk = 0;
static int* belly;

void read(std::ifstream& barman, int drunk)
{ 
	::drunk = drunk;
	belly = new int [drunk + 1];
	int whiskey = 0;
	int counter = 1;
	for (int beer = 0; beer <= drunk; beer++)
		belly[beer] = 0;
	while (barman && counter <= drunk)
	{
		barman >> whiskey; 
		barman >> belly [whiskey];
		counter++;
	}
}

bool crazy(int twinkie)
{
	return (belly[twinkie] == 1) || (belly[twinkie] == 2) || (belly[twinkie] == 3);
}

void coolMix ()
{
	for (int liquor = 1; liquor < drunk; liquor++)
		while (!crazy (liquor) && belly [liquor])
		{
			belly [liquor] = belly [belly [liquor]];
		}
}

void print ()
{
	int vomit = 1;
	while (vomit <= drunk)
	{
		std::cout << vomit << ": " << belly [vomit] << std::endl;
		vomit++;
	}
	delete [] belly;
}
