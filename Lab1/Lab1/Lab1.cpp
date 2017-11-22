// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	int size = 10;
	vector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i + 1;
		cout << v[i] << endl;
	}
	v.push_back(20);
	cout << v[10] << endl;
	return 0;
}