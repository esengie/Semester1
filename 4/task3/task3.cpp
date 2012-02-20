#include "stdafx.h"
#include "C:\Users\esengie\Documents\Programming\Modules\1 list\1lists.h"
void intro();

void main(void)
{
	int i = 1;
	int x = 0;
	List1Element * head = createList();
	intro();
	scanf ("%d", &i);
	while (i)
	{
		switch (i)
		{
			//case 0:
			//	delList(head);
			//	break;
			case 1 :
				printf("enter the value\n");
				scanf("%d", &x);
				insertEl (head, x);
				break;
			case 2 :
				if (isEmpty(head))
					printf("sorry it seems to be nothing here\n");
				else
					printf("%d\n", getMin(head));
				break;
			case 3:
				if (isEmpty(head))
					printf("sorry it seems to be nothing here\n");
				else
					printList(head);
					printf("\n");
				break;
			default:
				printf("no no no, you're doing it wrong!\n");
		}
		if (i)
		{
			intro();
			scanf ("%d", &i);
		}
	}
	delList(head);
	delete head;
}


void intro(void)
{
	printf("\n	0 - exit\n\
	1 - add value to sorted list\n\
	2 - remove value from list\n\
	3 - print list\n");
}