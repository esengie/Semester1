#include "stdafx.h"
#include "tree.h"
#include <iostream>

inline static int
MIN(int a, int b) {
   return  (a < b) ? a : b;
}

 inline static int
MAX(int a, int b) {
   return  (a > b) ? a : b;
}

enum balance_t { LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = 1 };

enum height_effect_t { HEIGHT_NOCHANGE = 0, HEIGHT_CHANGE = 1 };
   // Return true if the tree is too heavy on the left side
inline static int
LEFT_IMBALANCE(short bal) {
   return (bal < LEFT_HEAVY);
}

   // Return true if the tree is too heavy on the right side
inline static int
RIGHT_IMBALANCE(short bal) {
   return (bal > RIGHT_HEAVY);
}






Tree* Tree::insert(int val)
{
	if (!this->value)
	{
		value = val;
		return this;
	}
	if (this->value == val)
		return this;
	else if (this->value > val)
	{
		if (left)
			return left->insert(val);
		else 
			return (left = new Tree(val));
	}
	else
	{
		if (right) 
			return right->insert(val);
		else 
			return (right = new Tree(val));
	}
}
Tree* Tree::deleteVal(int val)
{
	if (find(val))
	{
		Tree *tmp = this;
		deleteHelp(tmp, val);
		return tmp;
	}
	else 
		return this;
}
void Tree::deleteHelp(Tree*& t, int val)
{
	//if (!t) return;
	if (t->value > val)
		deleteHelp(t->left, val);
	else if(t->value < val)
		deleteHelp(t->right, val);
	else
	{
		if (!t->left && !t->right)
			{
				delete t;
				t = NULL;
			}
		else if (!t->left)
		{
			Tree* tmp = t->right;
			t->right = NULL;
			delete t;
			t = tmp;
		}
		else if (!t->right)
		{
			Tree* tmp = t->left;
			t->left = NULL;
			delete t;
			t = tmp;
		}
		else
			t->value = deleteMinTree(t->right);

	}
}

int Tree::deleteMinTree(Tree* & t)
{
	if (t->left)
		return deleteMinTree(t->left);
	else
	{
		int k = t->value;
		delete t;
		t = NULL;          // эта строчка обязательна?
		return k;
	}
}
bool Tree::find(int val)
{
	
	if (value == val)
		return true;

	if (value > val && left)
		return left->find(val);
	if (right)
		return right->find(val);

	return false;
}

void Tree::preOrder()
{
	std::cout << value << ' ';
	if (left)
		left->preOrder();
	if (right)
		right->preOrder();
}

void Tree::postOrder()
{
	
	if (left)
		left->postOrder();
	if (right)
		right->postOrder();
	std::cout << value << ' ';
}

void Tree::symmOrder()
{
	
	if (left)
		left->symmOrder();
	std::cout << value << ' ';
	if (right)
		right->symmOrder();
}

void Tree::asymmOrder()
{
	
	if (right)
		right->asymmOrder();
	std::cout << value << ' ';
	if (left)
		right->asymmOrder();
}

/*Tree* Tree::deleteVal(int val)
{
	Tree *tmp = this;
	deleteFromTree(tmp, val);
	return tmp;
}*/
