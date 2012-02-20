#include "StringStack.h"

string StringStack::getEl()
{
	if (!next)
		return NULL;
	StringStack* tmp = next;
	string tmpx = next->value;
	next = next->next;
	tmp->next = NULL;
	delete tmp;
	if (!next)
		current = NULL;
	return tmpx;
}


StringStack* StringStack::find(string val)
{
	StringStack* tmp = this;
	while (tmp && tmp->value.compare(val))
		tmp = tmp->next;
	return tmp;
}


void StringStack::insertEl(string val)
{
	//List* tmp = this;
	StringStack* tmpx = new StringStack;
	tmpx->value = val;
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



void StringStack::insert(string val)
{
	StringStack* tmp = next;
	if (tmp && (tmp = tmp->find(val)))
	{
		tmp->counter++;		  
	}
	else
	{
		insertEl(val); 
		current->counter = 1;	
	}
};


void StringStack::print()
{
	StringStack* tmp = next;
	while (tmp)
	{
		cout <<'\t' << tmp->value.c_str() << ' ' << tmp->counter << " times " << endl;
		tmp = tmp->next;
	}
	if (!this)
		cout << "empty";
}