#pragma once 
#include "string.h"
#include "iostream"
using namespace std;

struct Steel
{
	std::string name;
	int priority;
};

class StringStack 
{
public:
	StringStack (): current(NULL), next(NULL), counter(0)  { value.name = " "; value.priority = 0;}; 
	~StringStack ()	{ delete next;};
	void insert(Steel h);
	string getEl();
	bool empty () { return next; }
	int inclusions() {return counter;};
	//StringStack* find (Steel h);
	void print();
private:
	int counter;
	Steel value;
	StringStack* next;
	StringStack* current;
	//void insertEl (Steel h);
	
	
};
