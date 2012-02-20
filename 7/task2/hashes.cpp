#include "hashes.h"
StringStack* hashe[ARRAYLENGTH];
void createHash ()
{
	
		for (int i = 0; i < ARRAYLENGTH; i++)
			hashe[i] = new StringStack;

}

void deleteHash ()
{
	for (int i = 0; i < ARRAYLENGTH; i++)
		delete hashe[i];
}

static long long kr = 1;

int func (string h)
{
	int j = 0;
	string::iterator i = h.begin();
	while (i < h.end())
	{
		j += realFunc( *i, j);

		i++;
	}
	kr = 1;
	j %= ARRAYLENGTH;
	return j;
}


int realFunc ( char ch, int j)
{
	

	j = ((int (ch)) * kr) % ARRAYLENGTH;
	kr *= 11;
	return j;
}

void insertHash (string h)
{
	hashe[func(h)]->insert(h);
}

void printHash ()
{
	for (int i = 0; i < ARRAYLENGTH; i++)
		{
			std::cout << i << ":\n";
			hashe[i]->print();
		}
}