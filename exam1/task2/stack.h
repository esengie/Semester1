struct Stack
{
	int value;
	Stack * next;
};

Stack * createStack();
void swap (char * a, char * b);
void push(Stack * head, int x);
int pop(Stack * head);
void delStack(Stack * head);
bool isEmpty (Stack * head);
void printStack (Stack * head);