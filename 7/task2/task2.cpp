// task2.cpp : Defines the entry point for the console application.
//
#include "StringStack.h"
#include "stdafx.h"
#include "string"
#include "iostream"
#include "fstream"
#include "hashes.h"



int _tmain(int argc, _TCHAR* argv[])
{
	createHash();
	std::string h;
	std::cout << "Write a filename\n";
	std::cin >> h;
	ifstream input (h.c_str());
	freopen("test.txt", "w", stdout);
	while (input)
	{
		h.clear();
		input >> h;
		insertHash (h);		
	}
	printHash();
	deleteHash();
	std::cin >> h;
	return 0;
}








