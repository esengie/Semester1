// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hashes.h"
#include "Rabin-Karp.h"
#include <fstream>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string h;
	char peek = '\0';

	std::cout << "Please input a filename to search in" << std::endl;
	std::cin >> h;
	std::ifstream cinni (h.c_str());
	std::cout << "And now input a filename to search for" << std::endl;
	h.clear();

	std::cin >> h;
	std::ifstream searchy (h.c_str());
	//freopen ("test.txt", "w", stdout);
	h.clear();
	
	while (searchy)
	{
		searchy.get(peek);
		if (searchy)
			h += peek;
	}
	//std::cout << h;

	if (Rabin::search(cinni, h))
		std::cout << "Welp it seems i found it" << std::endl;
	else
		std::cout << "Welp it seems i didn't find it" << std::endl;

	




	std::cin >> h;
	return 0;
}

