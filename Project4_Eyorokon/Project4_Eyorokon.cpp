// Project4_Eyorokon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HashTable.h"
#include <string>

using namespace std;

int main()
{
	//HashTable<string> t;
	HashTable<int> t;
	int col=0, row;
	cout << "first 12 "<< t.insert(12, 7777 , col) << endl; //Test insert.
	cout <<"second 12 "<< t.insert(12, 7878, col) << endl;  //Test Duplicate entry
	row = 12*12; //Quadratic insert
	cout << "Key: " << t.table[row][0] << ". Value: " << t.data[row] << endl; //Print where it should be
	system("pause");
    return 0;
}

