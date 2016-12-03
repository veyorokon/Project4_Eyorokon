// Project4_Eyorokon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HashTable.h"
#include <string>


using namespace std;

int main()
{
	HashTable<int> t;
	cout << to_string(t.table[0][1]);
	system("pause");
    return 0;
}

