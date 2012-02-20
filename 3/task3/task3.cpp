//можно не посимвольно считывать?

#include "stdafx.h"
#include "C:\Users\esengie\Documents\Programming\Modules\1 list\stack.h"
void calc(char * s);
bool isDigit(int i);
bool isOp(int i);
bool isHigher(int i, int j);
void main()
{	
	char s[100] = "\0";
	scanf("%s", s);
	calc (s); 
	scanf("%*S");
}

bool isDigit(int i)
{
	return (0 <= (i - '0') && (i - '0') <= 9);
}
bool isOp(int i)
{
	return (i == '+' || i == '-' || i == '*' || i == '/');

}
bool isHigher(int i, int j)
{
	return ((i == '/' || i == '*') && (j == '-' || j == '+'));
		
}
void calc(char *inf)
{
	if (isDigit (inf[0]) || inf[0] == '(')
	{
		int i = 0;
		char c = '\0';
		bool hasBracket = false;
		Stack * head = createStack();
		while ((inf[i] != '\0'))
		{
			if (isOp(inf[i]))
			{
				printf(" ");				
				if (!isEmpty(head))			
				{	
					c = pop(head);
					if (c == '(')						//again, check if bracket (it's second, first is down there)
						push(head, c);																	 
					else
						if (isHigher(inf[i], c))     //check if operand has higher priority 
								push(head, c);
						else
						{
							while (!isEmpty(head))
							{
								printf("%c ", c);
								c = pop(head);
							}
							printf("%c ", c);
						}
				}
				push(head, inf[i]);	
			}
			else 
				if (isDigit(inf[i]))               // check if number
					printf("%c", inf[i]);
				else								//check if bracket
					if (inf[i] == '(')
						push(head, inf[i]);
					else							//push all out till (
						if (inf[i] == ')')
						{
							c = pop(head);
							while ((c != '(') && (!isEmpty(head)))
							{
								printf("%c ", c);
								c = pop(head);
							}
						}
			i++;

		}
		while (!isEmpty(head))
			printf("%c ", pop(head));
	}
	else 
		printf("error");
}
