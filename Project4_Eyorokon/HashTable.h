#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T> class HashTable {
#define MAXHASH 1000
	
public:
	vector<vector<int>> table; // Stores our data :[0] key, [1] collisions
	vector<T> data; //Stores our data
	int size;

	/*Default constructor for the hash table.*/
	HashTable<T>::HashTable()
	{
		table.resize(MAXHASH, vector<int>(2, NULL));
		data.resize(MAXHASH, NULL);
		size = 0;
	}

	HashTable<T>::~HashTable()
	{
	}


	/*INSERT OPERATOR OVERLOADING HERE!!!!!!*/


	/* Inserts the key into the table. If the key is a duplicate, then the function
	returns false. Else the function returns true.*/
	bool HashTable<T>::insert(int key, T value, int& collisions) {
		int home = hash(key), index;
		if (data[home] == NULL) {
			assign(home, key, value);
			return true;
		}
		index = probe(home, key);
		if (index == -1) return false;
		assign(index, key, value);
		return true;
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
		int index = (key * key) % MAXHASH;
		return index;
	}

	/*Probes the table for the next available slot. Returns the first index found. */
	int HashTable<T>::probe(int home, int key) {
		int jump = 0, index = (jump+home)%MAXHASH;
		bool duplicate = isDuplicate(key, index);
		//Some hash function on index. - While - check duplicates (return -1)
		while (data[home+jump] != NULL && !duplicate) {
			jump = (10 + home) % MAXHASH;
		}
		if (duplicate) return -1;
		return index;
	}

	bool HashTable<T>::isDuplicate(int key, int index) {
		if (table[index][0] == key) return true;
		return false;
	}
	void HashTable<T>::assign(int index, int key, T value) {
		data[index] = value;
		table[index][0] = key;
	}
};

