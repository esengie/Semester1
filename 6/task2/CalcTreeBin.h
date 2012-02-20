#pragma once
#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;

class CalcTree
{
public:
	//friend std::ostream& operator<<(std::ostream& out, const CalcTree& self);
	//virtual void insert(char) = 0;
	virtual int result (void) const = 0;
	virtual void print(void) const = 0;
	virtual ~CalcTree(void) {};
};
class Leaf : public CalcTree
{
private: 
	int val; 
public:
	inline Leaf(string& s)
	{
		val = s[0] - '0';
		s.erase(0, 1);
	};
	inline int result (void) const 
	{
		return val;
	};
	void print (void) const 
	{
		cout << ' ' << val;
	};



};
class Operation : public CalcTree
{
private:
	char operand;
	CalcTree* left;
	CalcTree* right;
public:
	Operation (string& s);
	~Operation (void)
	{
		delete left;
		delete right;
	};
	int result (void) const;
	void print (void) const;
	CalcTree * build(string& s);
};
//std::ostream& operator<<(std::ostream& out, const CalcTree& self)
//{
//}