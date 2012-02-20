// task 2.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;
const int MAXARRAY = 100;					//max array
const int SOMEVALUE = 1000000;				//big enough value
int main(int argc, _TCHAR* argv[])
{
	
	int n = 0;
	int m = 0;
	cin >> n;						///uzel
	cin >> m;							////svyazka
	int a[MAXARRAY][MAXARRAY];		
	//int b[MAXARRAY];				
	bool c[MAXARRAY];				//remember if visited terminally 

	//init
	for (int i = 1; i <= n; i++)
	{
		//b[i] = SOMEVALUE;
		c[i] = false;
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = SOMEVALUE;
		}
	}

	//read
	
	for (int i = 1; i <= m; i++)
	{
		int from = 0;
		int to = 0;
		cin >> from >> to >> a[from][to];
	}
	c[1] = true;
	a[1][1] = 0;

	Queue<twom::two>* dji = new Queue<twom::two>;
	for (int i = 2; i <= m; i++)
	{
		if (a[1][i] != SOMEVALUE)
			dji->insertEl(&a[1][i]);
	}


	delete dji;
	return 0;
}

