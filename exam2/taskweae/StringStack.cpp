#include "StringStack.h"

string StringStack::getEl()
{
	if (!this->next)
		return NULL;
	StringStack* tmp = this->next;
	Steel tmpx = this->next->value;
	this->next = this->next->next;
	tmp->next = NULL;
	delete tmp;
	if (!this->next)
		current = NULL;
	return tmpx.name;
}

/*
StringStack* StringStack::find(Steel val)
{
	StringStack* tmp = this;
	while (tmp && tmp->value.compare(val))
		tmp = tmp->next;
	return tmp;
}
*/

void StringStack::insert(Steel val)
{
	//List* tmp = this;
	StringStack* tmpx = new StringStack;
	tmpx->value = val;
	if (!this->next)
	{
		//current = tmpx;
		tmpx->next = next;
		next = tmpx;
	}
	else
	{
		StringStack * tmp = this;
		while ((tmp->next) && (val.priority > tmp->next->value.priority))
		{
			tmp = tmp->next;
		};
		//StringStack * tmpx = new List1Element;
		//tmpx->value = x;
		tmpx->next = tmp->next;
		tmp->next = tmpx;
	}
}



/*void StringStack::insert(string val)
{
	StringStack* tmp = this->next;
	if (tmp && (tmp = tmp->find(val)))
	{
		tmp->counter++;		  
	}
	else
	{
		this->insertEl(val); 
		this->current->counter = 1;	
	}
};
*/

void StringStack::print()
{
	StringStack* tmp = this->next;
	while (tmp)
	{
		cout << tmp->value.name.c_str() << ' ' << tmp->value.priority<< endl;
		tmp = tmp->next;
	}
	if (!this)
		cout << "empty";
}   