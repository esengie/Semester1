// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fstream"
#include <string>
#include "sstream"
bool incorrect (std::string h);

int _tmain(int argc, _TCHAR* argv[])
{
	std::string h;
	std::cout << "Write a filename\n";
	//std::cin >> h;
	std::ifstream cin ("t.txt");//h.c_str());
	freopen("test.txt", "w", stdout);

	int year = 100000;
	int month = 32;
	int day = 65;

	while (cin)
	{
		int day1 = 66;
		int month1 = 33;
		int year1 = 1000000;
		char x = ' ' ;
		std::stringstream temp;
		cin >> h;
		temp << h;
		temp >> day1 >> x >> month1 >> x >> year1;
		if (day1 != 66 && month1 != 33 && year1 != 1000000)
		{
			if (year1 < year)
				{
					year = year1;
					month = month1;
					day = day1;
				}
			else
			{
				if (year1 == year && month1 < month)
				{
					year = year1;
					month = month1;
					day = day1;
				}
				else 
					if (year1 == year && month1 == month && day1 < day )
					{
						year = year1;
						month = month1;
						day = day1;
					}
			}
		}
	
		h.clear();
		//	continue;
		//char* curr = "\0";
		//h.copy(curr, 0, h.length());
		
		//std::cout << day << year;
		h.clear();

	}
	std::cout << day << '.' << month <<'.' << year;

	fclose (stdout);
	return 0;
}

bool incorrect (std::string h)
{

	return true;



}