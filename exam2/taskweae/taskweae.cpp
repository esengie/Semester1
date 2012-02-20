#include "stdafx.h"
#include <iostream>
#include "fstream"
#include <string>
#include "StringStack.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::string h;
	std::cout << "Write a filename\n";
	std::cin >> h;
	int n = 0;
	int m = 0;
	std::cout << "Write n and m\n";
	std::cin >> n >> m;
	std::ifstream cin (h.c_str());
	freopen("test.txt", "w", stdout);

	Steel temp;
	StringStack* cure = new StringStack;
	while (cin)
	{
		cin >> temp.name >> temp.priority;
		if (cin)
		cure->insert(temp);
	}
	//cure->print();
	std::cout << "Ex-people:" << std::endl << std::endl;
	while (cure->empty() && n)
	{
		std::cout << "\t" << cure->getEl() << std::endl;
		n--;
	}
	std::cout << std::endl << "Syberia is a harsh place:" << std::endl << std::endl;
	while (cure->empty() && m)
	{
		std::cout << "\t" << cure->getEl() << std::endl;
		m--;
	}
	std::cout << std::endl << "And these are lucky men!" << std::endl << std::endl;
	while (cure->empty())
	{
		std::cout <<"\t" << cure->getEl() << std::endl;
	}

	delete cure;
	fclose (stdout);


	return 0;
}

