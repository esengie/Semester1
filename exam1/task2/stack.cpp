#include "stdio.h"
#include "stack.h"

Stack * createStack()
{
	Stack * tmp = new Stack;
	tmp->value = 0;
	tmp->next =	NULL;
	return tmp;
}
void swap (char * a, char * b)
{
	char temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
void push (Stack * head, int x)
{
	Stack * tmp = new Stack;
	tmp->next = head->next;
	head->next = tmp;
	tmp->value = x;
}

bool isEmpty (Stack * head)
{
	return head->next? false : true;
}

int pop (Stack * head)
{
	Stack * tmp = head->next;
	int tempx = 0;
	head->next = tmp->next;
	tempx = tmp->value;
	delete tmp;
	return tempx;
}

void delStack (Stack * head)
{	
	Stack * tmp;
	while (head->next)
	{
		tmp = head->next;
		head->next = head->next->next;
		delete tmp;
	}
}

void printStack (Stack * head)
{
	Stack * tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

