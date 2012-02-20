#include "stdafx.h"
#include "CalcTreeBin.h"
#include <iostream>
#include <string>
#include <fstream>

int main()//int argc, _TCHAR* argv[])
{
	std::cout << "specify filename" << std::endl;
	std::string str;
	std::cin >> str;
	std::ifstream in (str.c_str());
	in >> str;
	Operation sfet(str);
	sfet.print();
	std::cout << std::endl;
	std::cout << sfet.result();
	std::cout << str;
	std::cin>> str;
	return 0;
}

