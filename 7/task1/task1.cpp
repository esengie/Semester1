#include "Expell.h"
#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "enter a filename\n";
	std::string h;
	std::cin >> h;
	int number = 0;
	std::ifstream inp (h.c_str());
	inp >> number;
	read(inp, number);
	coolMix();
	print();
	std::cin >> h;
	return 0;
}

