#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T> class HashTable {
#define MAXHASH 1000
	
public:
	vector<vector<int>> table; // Stores our data : key, collisions
	vector<T> data; //Stores our data
	int size;

	HashTable<T>::HashTable()
	{
		table.resize(MAXHASH, vector<int>(2, NULL));
		data.resize(MAXHASH, NULL);
		size = 0;
	}

	HashTable<T>::~HashTable()
	{
	}

	/* Inserts the key into the table. If the key is a duplicate, then the function
	returns false. Else the function returns true.*/
	bool HashTable<T>::insert(int key, T value, int& collisions) {
		int index = hash(key);

	}

	/*Removes the key from the table. Returns true if the key was successfully removed. Otherwise,
	the function returns false. */
	bool HashTable<T>::remove(int key) {

	}

	/*Searches the table for the key, returns true if the key is found. Else, the function returns
	false. */
	bool HashTable<T>::find(int key, T& value) {

	}

	/*Returns the loading factor of the table.*/
	float HashTable<T>::alpha() {

	}

	/*Returns the row index to insert key. If the first index hashed is not available,
	the function will call a probe hash function to probe the table for the next available index.*/
	int HashTable<T>::hash(int key) {
		int index;

	}

	/*Probes the table for the next available slot. Returns the first index found. */
	int HashTable<T>::probe() {

	}

};

