
#pragma once;
#include <iostream>
#include "1CrazyList.h"
namespace twom
{
	class two  
	{
	public:
		//friend class List<twom::two>;
		int* i;

		two () 
		{ 
			int* i = new int;
			i = NULL;
		}
		two (int* l) 
		{
			i = l;
		}
		~two () {};//delete i;}
		two& operator= ( const two& k)
		{
			i = k.i;
			return *this;
		}
		bool operator== (const two& l)
		{
			if (i && l.i)
			{
				return *i == *l.i;
			}
			else 
				if (!i && !l.i)
					return true;
				else 
					return false;
			//else return 0;
		}
		bool operator!= (const two& l)
		{
			if (i && l.i)
			{
				return *i != *l.i;
			}
			else 
				if (!i && !l.i)
					return true;
				else 
					return false;
			//else return 0;
		}
		bool operator< (const two& l)
		{
			if (i && l.i)
			{
				return *i < *l.i;
			}
			else 
				if (!i && !l.i)
					return true;
				else 
					return false;
		} 
		bool operator> (const two& l)
		{
			if (i && l.i)
			{
				return *i > *l.i;
			}
			else 
				if (!i && !l.i)
					return true;
				else 
					return false;
		} 
		bool operator! ()
		{
			return (bool(i));
		} 
		
	private:	
		friend std::ostream& operator<< (std::ostream& out, const two& self )
		{

			out << *self.i;
			return out;
		}
		friend std::istream& operator>> (std::istream& in, two& self)
		{
			in >> *self.i;
			return in;
		}
	};	
};
