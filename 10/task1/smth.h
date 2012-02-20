#pragma once 
#include "string.h"
#include "iostream"
//using namespace std;

struct Steel
{
	Steel(int a = 0, int b = 0): coeff(a), power(b) {};
	int coeff;
	int power;
	bool operator== (Steel& x)
	{
		return (this->coeff == x.coeff && this->power == x.power);
	}
	
};

class PoliStack 
{
public:
	PoliStack (): counter(0),  next(NULL), current(NULL)  { value.coeff = 0; value.power = 0;}; 
	~PoliStack ()	{ delete next; };
	
	void insert(Steel& h);

	Steel getEl();
	bool empty () { return next; }
	int inclusions() { return counter; } 
	//StringStack* find (Steel h);
	void print();
	static void add(PoliStack*& res, PoliStack * tmp,  PoliStack * tmpx = NULL) { insert(res, tmp); insert (res, tmpx);};
	static int valueX (PoliStack* , double x);
	static bool equals (PoliStack *, PoliStack *);
	//PoliStack operator()(const )

private:

	int counter;
	Steel value;
	PoliStack* next;
	PoliStack* current;
	static void insert (PoliStack *&, PoliStack * tmp) ;	
	//void insertEl (Steel h);
	
	
};
