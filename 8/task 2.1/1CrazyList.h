#pragma once
#include "iostream"
//#include "two.h"

template <class Tclass>
class List
{
public:
	List(): val(0), next(NULL), current(NULL), counter(0) { };
	~List();
	bool isEmpty () { return this->next == NULL; }
	Tclass getEl();
	List* find(Tclass value);
	virtual void insertEl (Tclass x);
	virtual List* getNext(List* t) {return t->next;};
	virtual void print (List* t) { cout << t->val << ' ';}; 
	virtual void printAll();
	List* last () {return current;};
	
protected:
		//List* head;
		List* next;
		Tclass val;
		List* current;
		int counter;
};






template <class Tclass>
List<Tclass>::~List()
{
	delete next;
};

template <class Tclass>
Tclass List<Tclass>::getEl()
{
	if (!this->next)
		return NULL;
	List* tmp = this->next;
	Tclass tmpx = this->next->val;
	this->next = this->next->next;
	tmp->next = NULL;
	delete tmp;
	if (!tmpx)
		current = NULL;
	return tmpx;
}

template <class Tclass>
List<Tclass>* List<Tclass>::find(Tclass value)
{
	List* tmp = this;
	while (tmp && tmp->val != value)
		tmp = tmp->next;
	return tmp;
}

template <class Tclass>
void List<Tclass>::insertEl(Tclass value)
{
	if (!List<Tclass>::find(Tclass value))
	{
	//List* tmp = this;
	List* tmpx = new List;
	tmpx->val = value;
	if (!this->next)
	{
		current = tmpx;
		this->next = current;
	}
	else
	{
		current->next = tmpx;
		current = tmpx;
	}
	}
}

template <class Tclass>
void List<Tclass>::printAll()
{
	List* tmp = this;
	while (tmp = getNext(tmp))
	{
		print(tmp);
	}
}
























template <class Tclass>
class Listez : public List<Tclass>
{
public:
                                     
	void insertEl (Tclass value, int count); 
	void printAll ();


};

template <class Tclass>
void InclusionsList<Tclass>::insertEl(Tclass value, int count)
{
	Listez* tmp = this;
	if (!tmp = tmp->find(value))
	{
		//tmp = dynamic_cast<List*>(this);
		tmp->List::insertEl(value); 
		tmp = tmp->List::last();
		tmp->counter = 1;
		InclusionsList*tmpx = dynamic_cast<InclusionsList*> (tmp);		
	}
};

template <class Tclass>
void InclusionsList<Tclass>::printAll()
{
	List* tmp = this;
	while (tmp = getNext(tmp))
	{
		tmp->print (tmp);
		//printCounter(tmp);
		cout << tmp->counter << " times " << endl;
	}
};