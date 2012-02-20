// task 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "1CrazyList.h"
//#include "two.h"
#include "fstream"
#include <string>



const int MAXARRAY = 100;					//max array
const int SOMEVALUE = 1000000;				//big enough value


int _tmain(int argc, _TCHAR* argv[])
{
	// just rerouting input (how jolly awful it would be to type all that everytime!)
	std::string h;
	std::cout << "Write a filename\n";
	std::cin >> h;
	std::ifstream cin (h.c_str());
	freopen("test.txt", "w", stdout);


	int n = 0;
	int m = 0;
	cin >> n;						///vertices
	cin >> m;							////edges
	
	int a[MAXARRAY][MAXARRAY];		 ////adjacency matrix

	
	bool visited[MAXARRAY];				//remember if visited terminally 


	//init


	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
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
		cin >> from >> to;
		cin >> a[from][to];
		a[to][from] = a[from][to];
	}


	PrioritySet* dji = new PrioritySet;
	for (int i = 2; i <= n; i++)
	{
		if (a[1][i] != SOMEVALUE)
			dji->insertEl(&a[1][i]);
	}





	while (!dji->isEmpty())
	{
		int i = (dji->getEl()) - &(a[1][0]);
		visited[i] = true;
		std::cout << i << ' ' << a[1][i] << ' ' << std::endl;
		for (int j = 2; j <= n; j++)
		{
			if (!visited[j] && a[i][j] != SOMEVALUE)
			{
				if (a[1][i] + a[i][j] < a[1][j])
					{
						a[1][j] = a[1][i] + a[i][j];
					}
				dji->insertEl(&a[1][j]);
			}
		}
	}


	delete dji;
	return 0;
}

