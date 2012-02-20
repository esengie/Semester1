#include "smth.h"
#include <cmath>


void PoliStack::insert (PoliStack*& resp, PoliStack * tmp) 
{  
	PoliStack* k = tmp; 
	if (!k) return;
	while (k = k->next) 
	{
		resp->insert(k->value);
	}
};

int PoliStack::valueX(PoliStack* resp, double x)
{
	PoliStack* k = resp; 
	int res = 0;
	while (k = k->next) 
	{
		res += k->value.coeff * (std::pow (x, k->value.power));
	}
	return res;
}


bool PoliStack::equals (PoliStack* resp, PoliStack * tmpx)
{
	PoliStack * tmp = resp;
	while (tmp && tmpx && tmp->value == tmpx->value)
	{
		tmp = tmp->next;
		tmpx = tmpx->next;
	}
	return (!tmp && !tmpx);
}


Steel PoliStack::getEl()
{
	if (!this->next)
		return this->value;
	PoliStack* tmp = this->next;
	Steel tmpx = this->next->value;
	this->next = this->next->next;
	tmp->next = NULL;
	delete tmp;
	if (!this->next)
		current = NULL;
	return tmpx;
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

void PoliStack::insert(Steel& val)
{
	//List* tmp = this;
	PoliStack* tmpx = new PoliStack;
	tmpx->value.coeff = val.coeff;
	tmpx->value.power = val.power;
	//val.coeff = 0;
	if (!this->next)
	{
		//current = tmpx;
		tmpx->next = next;
		next = tmpx;
	}
	else
	{
		PoliStack * tmp = this;
		while ((tmp->next->next) && (val.power < tmp->next->value.power))
		{
			tmp = tmp->next;
		};

		if (val.power == tmp->next->value.power)
		{
			tmp->next->value.coeff += val.coeff;
			if (!tmp->next->value.coeff)
			{
				PoliStack * tmp_ = tmp->next;
				tmp->next = tmp->next->next;
				tmp_->next = NULL;
				delete tmp_;
			}
			delete tmpx;
		}
		else
		{
			if (tmpx->value.power < tmp->next->value.power)
			{
				tmpx->next = tmp->next->next;
				tmp->next->next = tmpx;
			}
			else
			{
				tmpx->next = tmp->next;
				tmp->next = tmpx;
			}

		}
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

void PoliStack::print()
{
	PoliStack* tmp = this->next;
	while (tmp)
	{
		std::cout << tmp->value.coeff << "x^" << tmp->value.power;
		if (tmp = tmp->next) 
			std::cout << " + ";
	}
	if (!this)
		std::cout << "empty";
}   

