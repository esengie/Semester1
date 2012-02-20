#include "sadsdas.h"


bool run(const char *& word);
bool lvlPlusMinus(const char *&word);
bool lvlMulDiv(const char *&word);
bool lvlBrackNum(const char *&word);

inline bool delims(const char *&c)
{
    while (*c == ' ')
        c++;
    return (*c == 0);
}


inline bool isDig(char c)
{
    return (c <= '9' && c >= '0');
}



bool lvlPlusMinus(const char *&c)
{
    delims(c);
    if (!lvlMulDiv(c))
        return false;
    delims(c);
	while (*c == '+' || *c == '-')
    {
        c++;
		if (*c == '+' || *c == '-')
			return false;
        if (!lvlMulDiv(c))
            return false;
		//else return true;
    }
	//return true;
}
bool lvlMulDiv(const char *&c)
{
    delims(c);
    if (!lvlBrackNum(c))
        return false;
    delims(c);
    while (*c == '*' || *c == '/')
    {
        c++;
		if (*c == '*' || *c == '/' || *c == '+' || *c == '-')
			return false;
        if (!lvlBrackNum(c))
            return false;
    }
	//return true;
}
bool lvlBrackNum(const char *&c)
{
    if (delims(c))
        return false;
    if (*c == '(')
    {
        c++;
        if (!lvlPlusMinus(c))
            return false;
        if (delims(c))
			return false;
        if (*c != ')')
            return false;
        c++;
        return true;
    } 
	else 
		return run(c);
}








SymbolType next(const char *&word)
{
	char current = *word;
    word++;

    switch (current)
    {
		case '\0': 
			return terminator;
		case '+': case '*': case'/': case ')':           //well, future me, you get the idea
			word--;
			return terminator;
		case '-':
			//if (word[-1
		    return sign;
		case '.':
		    return point;
		case 'e': case 'E':
		    return exp;
		default:
		    if ((current >= '0') && (current <= '9'))
		        return digit;
		    return error;
    }
}

bool run(const char *& word)
{
	for (int state = init; ; )
    {
        SymbolType symbol = next(word);
        if (symbol == error)
            return false;
		if (state > move[symbol][state])         //// in case we have minus sign in here
		{
			word--;
			return true;
		}
        state = move[symbol][state];
        if (state == init)
            return false;
        if (state == OK)
            return true;
    }
}

bool parse (const char * word)
{
	//char* temp = word;
	return lvlPlusMinus(word);
}