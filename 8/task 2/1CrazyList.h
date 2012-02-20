#pragma once
#include "iostream"
//#include "two.h"











class List
{
public:
	List():val(NULL), next(NULL), current(NULL) {};//int* val = new int; val = NULL; };
	~List();
	bool isEmpty () { return next == NULL; }
	int* getEl();
	List* find(int* value);
	virtual void insertEl (int* x);
	virtual List* getNext(List* t) {return t->next;};
	virtual void print (List* t) { std::cout << *(t->val) << ' ';}; 
	virtual void printAll();
	List* last () {return current;};
	//int counter;
	
//protected:
		//List* head;
		List* next;
		int* val;
		List* current;
	//	friend class twom::two;
		
};







List::~List()
{
	//delete val;
	delete next;
};


int* List::getEl()
{
	if (!next)
		return NULL;
	List* tmp = next;
	// (tmpx) = new int;
	int*	tmpx= next->val;
	this->next = next->next;
	tmp->next = NULL;
	delete tmp;
	if (!tmpx)
		current = NULL;
	return tmpx;
}

List* List::find(int* value)
{
	List* tmp = this->next;
	while (tmp && *(tmp->val) != *(value))
		tmp = tmp->next;
	return tmp;
}


void List::insertEl(int* value)
{
	//List* tmp = this;
	List* tmpx = new List;
	tmpx->val = value;
	if (!next)
	{
		current = tmpx;
		next = current;
	}
	else
	{
		current->next = tmpx;
		current = tmpx;
	}
}


void List::printAll()
{
	List* tmp = this;
	while (tmp = getNext(tmp))
	{
		if (tmp->val)
		print(tmp);
	}
}





























class PrioritySet : public List
{
public:
                                     
	void insertEl (int* value); 
	//void printAll ();


};


void PrioritySet::insertEl(int* value)
{
	if (!List::find(value))
	{
		List* tmpx = new List;
		tmpx->val = value;
		if (!next)
		{
			current = tmpx;
			next = current;
		}
		else
		{
			List* tmp = this;
			while (*(tmp->next->val) < *(tmpx->val) && tmp->next->next)
				tmp = (tmp->next);
			if (*(tmp->next->val) < *(tmpx->val))
			{
				tmp->next->next = tmpx;
				tmpx->next = NULL;
				current = tmpx;
			}
			else 
			{
				tmpx->next = tmp->next;
				tmp->next = tmpx;
			}
		}


		
	}	
};

/*template <class Tclass>
void InclusionsList<Tclass>::printAll()
{
	List* tmp = this;
	while (tmp = getNext(tmp))
	{
		tmp->print (tmp);
		//printCounter(tmp);
		cout << tmp->counter << " times " << endl;
	}
};*/







































