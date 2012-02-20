#pragma once


enum  dir_t { LEFT = 0, RIGHT = 1 };

class Tree
{
public:

	Tree() : left(0), right(0), value(0) {};
	~Tree()
	{
		delete left;
		delete right;
	}
	Tree(int val): left(0), right(0), value(val) {};
	bool find(int val);
	Tree* insert(int val);
	Tree* deleteVal(int val);
	
	void postOrder();
	void preOrder();
	void symmOrder();
	void asymmOrder();
	
private:
	int value;
	Tree *left;
    Tree *right;
	int deleteMinTree(Tree*& t);
	void deleteHelp(Tree*& t, int val);

	
	/*void postOrder();
	void preOrder();
	void symmOrder();
	void resymmOrder();*/

};
