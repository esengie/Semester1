// i dunno, was pretty lazy with this one so...i'd say 20 minutes
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "StringStack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Enter filename" << std::endl;
	std::string h;
	std::string h2;
	std::string nomnom;
	std::cin >> h;
	std::ifstream secondCin (h.c_str());

	h.clear();

	std::cout << "Enter filename 2" << std::endl;
	std::cin >> h;
	freopen (h.c_str(), "r", stdin);

	h.clear();

	freopen ("test.txt", "w", stdout);


	StringStack* second = new StringStack;

	while (secondCin)
	{
		getline(secondCin, h);
		second->insert(h);
		h.clear();
	}
	while (std::cin)
	{
		getline(std::cin, h);
		if (second->find(h))
			std::cout << h << std::endl;
		h.clear();
	}

	delete second;
	fclose (stdin);
	fclose (stdout);
	return 0;
}

