// task 1.cpp : Defines the entry point for the console application.
//
#include "bubble.h"
#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	
	a = bubble::sort(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	cin >> n;

	return 0;
}

