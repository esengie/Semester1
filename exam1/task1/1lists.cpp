#include "stdio.h"
#include "1lists.h"

List1Element * createList()
{
	List1Element * tmp = new List1Element;
	tmp->value = 0;
	tmp->next =	NULL;
	return tmp;
}
void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

bool isEmpty (List1Element * head)
{
	return head->next == NULL;
}

int getMin (List1Element * head)
{
	List1Element * tmp = head->next;
	int tempx = 0;
	head->next = tmp->next;
	tempx = tmp->value;
	delete tmp;
	return tempx;
}

int getMax (List1Element * head)
{
	List1Element * tmp = head->next;
	int tempx = 0;
	head->next = tmp->next;
	tempx = tmp->value;
	delete tmp;
	return tempx;
}

void delList (List1Element * head)
{	
	List1Element * tmp;
	while (head->next)
	{
		tmp = head->next;
		head->next = head->next->next;
		delete tmp;
	}
}

void insertEl (List1Element * head, int x)
{
	
	if (isEmpty(head))
	{
		List1Element * tmp = new List1Element;
		head->next = tmp;
		tmp->value = x;
		tmp->next = NULL;
	}
	else
	{
		List1Element * tmp = head;
		while ((tmp->next) && (x > tmp->next->value))
		{
			tmp = tmp->next;
		};
		List1Element * tmpx = new List1Element;
		tmpx->value = x;
		tmpx->next = tmp->next;
		tmp->next = tmpx;
	}
}

void printList (List1Element * head)
{
	List1Element * tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

