// expected 15 min
// done 10 min
//

#include "stdafx.h"
#include "1lists.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int m = 0;
	int n = 0;
	List1Element * head = createList();
	printf("enter the quantity of conspects of vasya\n");
	scanf ("%d", &m);
	printf ("now enter chatacteristics of each conspect\n");
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &n);
		insertEl(head, n);
	}
	n = 0;
	m = 0; 

	printf("enter the quantity of conspects of petya\n");
	scanf ("%d", &m);
	printf ("now enter chatacteristics of each conspect\n");
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &n);
		insertEl(head, n);
	}

	printList(head);
	delList(head);
	scanf("%*s");
	return 0;
}

