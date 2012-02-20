// took longer than exponentected..
//	...actually i didn't know the task (...misinterpreted it)
#include <stdlib.h>
#include "stdafx.h"
#include <iostream>
using namespace std;
const long long limit = 3*10e10;

int _tmain(int argc, _TCHAR* argv[])
{
	double doubleNum = 0;
	long long numberBinary = 0;
	long long mantissa = 0;
	int k = 0;
	int exponent = 0;
	int i = 0;
	long long mask = 0;
	long long exponenton = 0;





	while (!cin.eof())
	{
		mantissa = 0;
		mask = 0x1000000000000000;
		exponenton = 5;
		cin >> doubleNum;
		k = sizeof (doubleNum)/sizeof (char);

		bool isSign = *((unsigned char *)(&doubleNum) + k-1) >> 7;

		exponent = *((unsigned char *)(&doubleNum) + k-1) & 0177;
		exponent *= 16;
		exponent = ((*((unsigned char *)(&doubleNum) + k-2) & ~017) >>4)    + exponent - 1023 ; 

		numberBinary = *((unsigned char *)(&doubleNum) + k-2) & 017;
		numberBinary += 16;            // this will be needed below
		i = k - 3;
		while (i >= 0)
		{
			numberBinary *= 256;
			numberBinary += *((unsigned char *)(&doubleNum) + i);
			i--;
		}
		numberBinary *= 32;

	
		while (!(numberBinary & mask) && numberBinary)       ///that thing is needed here (format is 1,10100010111010101 so it is the first '1')
			mask >>= 1;
		numberBinary &= ~mask;					// but we don't need that '1' anymore so delete it 
		mask >>= 1;					// and move mask a little right
		mantissa = 10;						//because we actually had that invisible '1' at the start (it is implyed)
		while (numberBinary && exponenton < limit)
		{
			mantissa += (((bool)(numberBinary & mask))* exponenton);
			exponenton *= 5;
			mantissa *= 10;
			numberBinary <<= 1;
		}
		
		if (exponent == -1023)
			cout << "0.0" << endl;
		else
		{
			long long cmp = 1;				//beautifying output
			char ch = (isSign? '-' : ' ');
			while (mantissa > cmp)  
				cmp *= 10;
			if (cmp != mantissa)
				cmp /= 10;
			if (exponent > 0)
				while (mantissa < cmp * 5 && exponent)
				{
					mantissa *= 2;
					exponent--;
				}
	
			cout << ch << mantissa / cmp << ".";
	
			while (mantissa >= cmp)
			{
				mantissa -= cmp;
			}
			if (mantissa)
			{
				while (cmp/mantissa > 10)
				{
					cout << "0";
					cmp /= 10;
				}
				cout << mantissa;
			}
			else 
				cout << "00";
			if (exponent)
				cout << "x2^(" << exponent << ")" << endl;
			else
				cout << "00" << endl;
		}
	}
	return 0;
}

