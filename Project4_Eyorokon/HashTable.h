#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T> class HashTable {
#define MAXHASH 1000
#define MAXPRIME 997	
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
			assign(home, key, value, 0);
			return true;
		}
		collisions += 1;
		index = probe(home, key, collisions);
		if (index == -1) return false;
		assign(index, key, value, collisions);
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

	/*Quadratic hash returns the row index modded by MAXHASH to insert key.*/
	int HashTable<T>::hash(int key) {
		return(key * key) % MAXHASH;
	}

	/*Probes the table for the next available slot. Returns the first index found. */
	int HashTable<T>::probe(int home, int key, int &collisions) {
		int jump = 0, index = (jump+home)%MAXHASH;
		bool duplicate = isDuplicate(key, home);
		//Some hash function on index. - While - check duplicates (return -1)
		while (data[index] != NULL) { //Loop until we find an open spot
			if (duplicate) return -1; //if duplicate return 
			jump = (MAXPRIME-(key % MAXPRIME)); //update the jump value using Double hash
			cout << "Key: " << key << " jumped by: " << jump << endl;
			index = (home + jump) % MAXHASH; //update the index to equal jump value + home
			duplicate = isDuplicate(key, index); //Check for duplicates
			collisions += 1;
		}
		return index; //return index
	}

	/*Checks if the key at the index is equal to a given key and returns approprate bool value.*/
	bool HashTable<T>::isDuplicate(int key, int index) {
		if (table[index][0] == key) return true;
		return false;
	}

	/*Assign key and value at index(row) in both table and data vectors.*/
	void HashTable<T>::assign(int index, int key, T value, int collisions) {
		data[index] = value;
		table[index][0] = key;
		table[index][1] = collisions;
		size++; 
	}
};

