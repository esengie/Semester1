// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
#include <string>
#include "sstream"

int _tmain(int argc, _TCHAR* argv[])
{
	std::string h;
	std::cout << "Write a filename\n";
	std::cin >> h;
	std::ifstream cin (h.c_str());
	std::stringstream temp;
	std::stringstream temp2;
	//freopen(h.c_str(), "r", stdin);
	
	int a = 0;
	int b = 0;
	int curr = 0;
	std::cout << "Enter a and b" << std::endl;
	std::cin >> a >> b;
	freopen("test.txt", "w", stdout);
	while (cin)
	{
		cin >> curr;
		if (curr < a)
			std::cout << curr << " ";
		if (curr >= a && curr <= b)
			temp << curr << " ";
		if (curr > b)
			temp2 << curr << " ";
	}
	
	std::cout << temp.str();
	std::cout << temp2.str();
	
	fclose (stdout);
	return 0;
}

