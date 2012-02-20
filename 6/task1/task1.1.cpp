#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "tree.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "0 - exit\n";
    cout << "1 - add a value to a set\n";
    cout << "2 - remove a value from the set\n";
    cout << "3 - finds a value in the set\n";
	cout << "4 - print sorted set from low to high\n";
	cout << "5 - print sorted set from high to low\n";
	Tree *t = new Tree();

	while(true)
	{
		cout << "Enter a command from the list above:\n";
		int command = 0;
		cin >> command;
		int val = 0;
		switch (command)
		{
			case 0:
				delete t;
				return 0;
			case 1:
				cout << "Input added value:\n";
				
				cin >> val;
				t->insert(val);
				break;
			case 2:
				cout << "Input value to remove:\n";
				
				cin >> val;
				t = t->deleteVal(val);
				if (!t)
					Tree* t = new Tree;
				break;
			case 3:
				cout << "Value to find:\n";
				
				cin >> val;
				cout << (t->find(val) ? "true" : "false") << endl;
				break;
			case 4:
				cout << "The list:\n";
				if (t)
					t->symmOrder();
				else 
					cout << '0';
				cout << endl;
				break;
			case 5:
				cout << "The list:\n";
				if (t)
					t->asymmOrder();
				else 
					cout << '0';
				cout << endl;
				break;
			default:
				cout << "Sorry, unknown command...maybe you'll try again?\n";
				break;
		};

	}
	
	
	
	scanf("%*s");
	return 0;
}

