#pragma once 
#include "string.h"
#include "iostream"
//using namespace std;

class StringStack 
{
public:
	StringStack (): counter(0), value(""), next(NULL), current(NULL)  {}; 
	~StringStack ()	{  delete next;};
	void insert(std::string h);
	std::string getEl();
	int inclusions() {return counter;};
	StringStack* find (std::string h);
	void print();
private:
	int counter;
	std::string value;
	StringStack* next;
	StringStack* current;
	void insertEl (std::string h);
	
	
};
