#include "hashes.h"
#include "StringStack.h"
#include "string"
#include "iostream"


namespace hashes
{
	
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


int func (std::string h, char ghr)
{
	static int memorize = 0;
	static int memo = 1;
	int kr = 0;
	if (ghr == 0)
	{
		std::string::iterator i = h.begin();
		int j = 0;
		memo = 0;
		while (i < h.end())
		{
			kr *= PRIME;
			kr += int(h[j]);
			kr %= ARRAYLENGTH;
			if (memo)
				memo = (PRIME * memo) % ARRAYLENGTH;
			else 
				memo = 1;
			i++;
			j++;
		}
		memorize = kr;
		
	}
	else
	{
		kr = (memorize + ARRAYLENGTH - memo * int(ghr) % ARRAYLENGTH) * PRIME + int(h[h.size() - 1]);
		kr %= ARRAYLENGTH;
		memorize = kr;
	}


	//j %= ARRAYLENGTH;
	return kr;
}




void insertHash (std::string h, int i)
{
	hashe[i]->insert(h);
}

void printHash ()
{
	for (int i = 0; i < ARRAYLENGTH; i++)
		{
			std::cout << i << ":\n";
			hashe[i]->print();
		}
}

bool find(std::string h, int hashfunction)
{
	return hashe[hashfunction]->find(h);
}





}