#include "stdafx.h"
#include "C:\Users\esengie\Documents\Programming\Modules\1 list\1listscircle.h"

void main(void)
{
	int num = 0;
	int max = 5;
	int needed = 2;
	int j = 1;
	//scanf("%d", &max);
//	scanf("%d", &needed);
	List1Element * head = createList();
	while (j <= max)
	{
		for (int i = 1; i <= max; i++)
			insert(head, i);
		List1Element * temp = head->next;
		while (!isEmpty(head))
			temp = circGet (temp, j, head, &num);
		if (num == needed)
			printf ("%d ", j);
		j++;
	}
	scanf("*S");
}

