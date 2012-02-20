#pragma once 
#include "string.h"
#include "iostream"
using namespace std;

class StringStack 
{
public:
	StringStack (): current(this), next(NULL), counter(0), value("") {}; 
	~StringStack ()	{  delete next;};
	void insert(string h);
	string getEl();
	int inclusions() {return counter;};
	StringStack* find (string h);
	void print();
private:
	int counter;
	string value;
	StringStack* next;
	StringStack* current;
	void insertEl (string h);
	
	
};
