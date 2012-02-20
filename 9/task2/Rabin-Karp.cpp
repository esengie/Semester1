
#include <string>
#include <fstream>
#include "Rabin-Karp.h"
#include "hashes.h"

bool Rabin::search(std::ifstream& inni, const std::string& whatfor)
{
	int ifunc = hashes::func(whatfor);
	char token = '\0';
	std::string h;

	for (int j = 0; j < whatfor.size(); j++)
	{
		if (!inni) 
			return false;
		inni.get(token); 
		if (inni)
			h += token;
	}

	if (hashes::func(h) == ifunc)
		if (h == whatfor)
		return true;


	//hashes::createHash();
	while(inni)
	{
		inni.get(token);
		char stam = '\0';
		if (inni)
		{
			stam = h[0];
			h.erase(0, 1);
			h += token;
		}
		if (hashes::func(h) == ifunc)
			if (h == whatfor)
				return true;
	}
	//hashes::printHash();
	//hashes::deleteHash();
	return false;
}