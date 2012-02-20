#include "stdafx.h"
#include "C:\Users\esengie\Documents\Programming\Modules\1 list\1lists.h"

int main()
{
	int temp = 0;
	int tempo = 0;
	List1Element * head = createList(); 
	int n = 0;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		insertEl(head, temp);
	};
	while ((temp != tempo) && (!isEmpty(head)))
	{
		tempo = temp;
		temp = getMax (head);
	}
	printf((tempo != temp)? "no element found" : "%d", temp);
	
	scanf("%*s");
}

