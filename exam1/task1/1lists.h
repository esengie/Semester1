struct List1Element
{
	int value;
	List1Element * next;
};

List1Element * createList();
void swap (int * a, int * b);
int getMin(List1Element * head);
int getMax(List1Element * head);
void insertEl(List1Element * head, int x);
void delList(List1Element * head);
bool isEmpty (List1Element * head);
void printList (List1Element * head);