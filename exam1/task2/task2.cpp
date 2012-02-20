// expected 20 min
// done in 20 min
//
#include "math.h"
#include "stdafx.h"
#include "stack.h"

int const alength = 1000;

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	Stack * head = createStack();
	char s[alength] = "\0";
	printf("print file\n");
	fgets(s, alength, stdin);
	while (s[i] != '\0')
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			push (head, s[i]);
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (isEmpty(head) || (abs(s[i] - pop(head)) > 2))
			{
				printf("incorrect brackets order");
				delStack(head);	
				return 0;
			}

		}
		i++;
	}
	printf(isEmpty(head)? "correct brackets order" : "incorrect brackets order");
	delStack(head);	
	return 0;
}

