#include <iostream>
#include <string>
using namespace std;

int main ()
{
	
	while (!cin.eof())
	{
		string str = "\0";
		int pos = 0;
		int pos2 = 0;
		int pos3 = -1;

		getline(cin, str);
		
		while ((pos2 = str.find("\"")) != string::npos)
		{
			pos3 = str.find("\"", pos2 + 1);
			if (pos3 == string::npos)
				str.clear();
			else
				str.erase (0, pos3 + 1);
		}
		pos = str.find("\/\/");
		if (pos != string::npos)
			cout << str.substr(pos) << '\n';
	}
  return 0;
}