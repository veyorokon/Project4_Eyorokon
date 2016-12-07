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

int main()
{
	//HashTable<string> t;
	HashTable<int> t;
	
	int col = 0;

	//Random number generator code borrowed from pilot.
	srand((unsigned int)time(NULL));
	/* generate secret number between 1 and 10: */
	
	for (int i = 0; i < 1000; i++) {
		int random = rand() % 1000 + 0;
		cout << "Key: " << random << " inserted at: ";
		t.insert(random, random/2, col);
		cout << endl;
	}
	//cout << endl << t;
	/*cout << endl << endl;
	int val;
	cout << t.find(666, val);
	cout << "Value: for 666: " << val << endl;
	cout << "Removed." << endl;
	t.remove(666);
	cout << t.find(666, val);*/
	/*
	int a = t.size;

	for (int i = 0; i < 1000; i++) {
		int random = rand() % 1000 + 0;
		if(t.remove(random)) cout << "Key: " << random << " removed. ";
		else (cout << "Key: " << random << " not found.");
		cout << endl;
	}
	int b = t.size;
	*/
	//cout << t;
	//cout << "Size before: " << a << ". Size after: " << b << endl;
	system("pause");
    return 0;
}

