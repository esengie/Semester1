#include "smth.h"
#include <iostream>

void specify (PoliStack *& t);
int main()
{
	bool isCreated = false;
	int thingy = -1; 
	int a = 0;
	PoliStack* bot = new PoliStack();
	PoliStack* top = new PoliStack();


	while (std::cin)
	{
		std::cout << "Input 0 to to make it all go away\n";
		std::cout << "Input 1 to create a new polynomial\n";
		std::cout << "Input 2 to evaluate the polynomial\n";
		std::cout << "Input 3 to add coefficients to the polynomial\n";
		std::cout << "Input 4 to check equality of a polynomial to the polynomial\n";
		std::cin >> thingy;
		
		switch (thingy)
		{
		case 1:
x:			if (isCreated)
				{
					std::cout << "Oh you!\n";
					continue;
				}
			isCreated = true;
			specify (bot);
			break;
		case 2:
			if (!isCreated)
			{
				std::cout << "Could you specify the polynomial first?\n";
				goto x;
			}
			std::cout << "A point to evaluate it on\n";
			bot->print();
			std::cout << " = ";
			std::cin >> a;
			std::cout << PoliStack::valueX(bot, a) << std::endl;
			break;
		case 3:
			if (!isCreated)
			{
				std::cout << "Could you specify the polynomial first?\n";
				goto x;
			}
			specify(bot);
			break;
		case 4: 
			if (!isCreated)
			{
				std::cout << "Could you specify the polynomial first?\n";
				goto x;
			}
			isCreated = true;
			specify (top);
			if (PoliStack::equals(bot, top))
			{
				std::cout << "It does equal\n";
			}
			else
			{
				std::cout << "It does not equal\n";
			}
			break;

		case 0: 
			delete bot;
			delete top;
			return 0;		
		}
	}
}



void specify (PoliStack *& t)
{
	int a = 0;
	int b = 0;
	while (std::cin && a > -1)
	{
		std::cout << "Please enter power and coefficient or smth with negative power to get out\n";
		std::cin >> a >> b;
		Steel space(b, a);      
		if (a <= -1)
			continue;
		t->insert(space);		
	}
}
