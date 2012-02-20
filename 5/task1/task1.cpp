using namespace std;
#include <iostream>

void createCheck(bool *s);
bool isInside(bool *s, char ch);


int main()
{
	bool check [25];
	char str[255] = "\0";
	int i = 0;
	cout << "enter lines of text and if you get sleepy hit ctrl+Z and enter" << endl;
	while (!cin.eof())
	{
		createCheck(check);
		cin >> str;
		i = 0;
		while (str[i] != '\0')
		{
			if (isInside(check, str[i]))
			{
				cout << str [i];
			}
			i++;
		}
		cout << endl;
	}
	return 0;
}



void createCheck(bool *s)
{
	for (int i = 'a'; i < 'z'; i++)
	{
		s[i - 'a']= true;
	}
}

bool isInside(bool *s, char ch)
{
	if ('A' <= ch && ch <= 'Z')
	{	
		ch += 32;
	}
	if (s[ch - 'a'] == true)
	{
		s[ch - 'a'] = false;
		return true;
	}
	else 
		return false;
}









