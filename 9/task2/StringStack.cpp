#pragma once
#include "StringStack.h"

std::string StringStack::getEl()
{
	if (!this->next)
		return NULL;
	StringStack* tmp = this->next;
	std::string tmpx = this->next->value;
	this->next = this->next->next;
	tmp->next = NULL;
	delete tmp;
	if (!this->next)
		current = NULL;
	return tmpx;
}


StringStack* StringStack::find(std::string val)
{
	StringStack* tmp = this;
	while (tmp && tmp->value.compare(val))
		tmp = tmp->next;
	return tmp;
}


void StringStack::insertEl(std::string val)
{
	//List* tmp = this;
	StringStack* tmpx = new StringStack;
	tmpx->value = val;
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



void StringStack::insert(std::string val)
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


void StringStack::print()
{
	StringStack* tmp = this->next;
	while (tmp)
	{
		std::cout << tmp->value.c_str() << ' ' << tmp->counter << " times " << std::endl;
		tmp = tmp->next;
	}
	if (!this)
		std::cout << "empty";
}