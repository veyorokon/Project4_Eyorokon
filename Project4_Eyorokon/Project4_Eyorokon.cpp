// Project4_Eyorokon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HashTable.h"
#include <string>

/*Random number generator code for testing borrowed from Pilot*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void insert(HashTable<int>&);
int main()
{
	//HashTable<string> t;
	HashTable<int> t;
	
	insert(t);
	//Random number generator code borrowed from pilot.
	
	/* generate secret number between 1 and 10: */
	
	

	//cout << endl << t;
	/*
	int col = 0;
	for (int i = 0; i < 1000; i++) {
		int random = rand() % 1000 + 0;
		//cout << "Key: " << random << " inserted. ";
		t.insert(random, random / 2, col);
		//cout << endl;
	}
	*/
	for (int i = 0; i < 1000; i++) {
	int random = rand() % 1000 + 0;
	if(t.remove(random)) cout << ". Key: " << random << " removed. ";
	else (cout << "Key: " << random << " not found.");
	cout << endl;
	}
	
	
	int val;
	for (int i = 0; i < 1000; i++) {
		int random = rand() % 1000 + 0;
		cout << "Key: " << random << " found. ";
		t.find(random, val);
		cout << endl;
	}
	//cout << t.size;
	cout << t;
	
	
	system("pause");
    return 0;
}

void insert(HashTable<int>& table) {
	srand((unsigned int)time(NULL));
	int col;
	/*
	while (table.size < 1000) {
		int random = rand() % 1000 + 0;
		//cout << "Key: " << random << " inserted. ";
		table.insert(random, random / 2, col);
		cout << table.size << endl;
	}*/

	for (int i = 0; i < 1000; i++) {
		table.insert(i, 12, col);
		cout << i << endl;
	}
	//cout << table;

}
