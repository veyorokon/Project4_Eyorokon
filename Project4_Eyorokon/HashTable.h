#pragma once
#include <iostream>
#include <string>
#include "Record.h"
#include <iomanip>
#include <float.h>

#define MAXHASH 1000
#define HASHPRIME 769

using namespace std;

template <class T> class HashTable {


public:
	Record<T>* table;
	int size;
	/*Default constructor for the hash table.*/
	HashTable<T>::HashTable()
	{
		table = new Record<T>[MAXHASH];
		//create(0, 12, 9999);
		size = 0;
	}

	HashTable<T>::~HashTable()
	{
	}


	/*INSERT OPERATOR OVERLOADING HERE!!!!!!*/
	friend ostream& operator<<(ostream& os, HashTable& me) {
		for (int i = 0; i < MAXHASH; i++) 
			os << "Index: "<< i << ". " << me.table[i] << endl;
		return os;
	}

	/* Inserts the key into the table. If the key is a duplicate, then the function
	returns false. Else the function returns true.*/
	bool HashTable<T>::insert(int key, T value, int& collisions) {
		int collides = 1;
		int index = (key*key) % MAXHASH; //Quadratic hash
		collisions = collides;
		if (table[index].isEmpty()) return create(index, key, value, collisions); //If index is empty - create new record.
		collides++; //Increment collision count
		index = probe(index, key); //Else double hash for new index
		while (!table[index].isEmpty()) {
			if (table[index].getKey() == key) {//Does that index have an equal key?
				if (!table[index].isTombstone()) {//If so, is it a tombstone?
					//cout << "Duplicate.";
					collisions = collides;//If it isn't a tombstone, return false;
					return 0;
				}
				return create(index, key, value, collisions);//If not, create the node if the index was removed previously.
			}
			index++;//Linear probe from second index
			index %= MAXHASH;//Bound check
			collides++; //update collisions
		}
		collisions = collides;
		//cout << index << ". Collisions: "<< collisions << ". Expected: "<< expectedCollisions();
		
		return create(index, key, value, collides);//create the node
	}

	/*Removes the key from the table. Returns true if the key was successfully removed. Otherwise,
	the function returns false. */
	bool HashTable<T>::remove(int key) {
		int index = hash(key), home = index; //Declare vars
		if (table[index].getKey() == key) {
			table[index].kill();//kill index that has key.
			size--;
			return true;//check if first hash index has key
		}
		index = probe(index, key);//get probe index 
		while (index != home) {
			if (table[index].getKey() == key) {
				table[index].kill();//delete the index if it has the key
				size--;
				return true;//return true if probe index has key
			}
			index++;
			index %= MAXHASH;
		}
		return false;
	}

	/*Searches the table for the key, returns true if the key is found. Else, the function returns
	false. */
	bool HashTable<T>::find(int key, T& value) {
		int index = hash(key), home = index; //Declare vars
		if (table[index].getKey() == key && !table[index].isTombstone()) {
			value = table[index].getValue();//save return value
			return true;//check if first hash index has key
		}
		index = probe(index, key);//get probe index 
		while (index != home) {
			if (table[index].getKey() == key && !table[index].isTombstone()) {
				value = table[index].getValue();//save return value
				return true;//return true if probe index has key
			}
			index++;
			index %= MAXHASH;
		}
		cout << "Not found" << endl;
		return false;
	}

	/*Returns the loading factor of the table.*/
	float HashTable<T>::alpha() {
		float a = (float(size) / MAXHASH);
		return a;
	}

	/*Returns the loading factor of the table.*/
	float HashTable<T>::expectedCollisions() {
		float a = alpha();
		float collisions = float(1 / (1 - a));
		collisions = floor(collisions + 0.5);
		return collisions;
	}

	/*Quadratic hash returns the row index modded by MAXHASH to insert key.*/
	int HashTable<T>::hash(int key) {
		return(key * key) % MAXHASH;
	}

	/*Probes the table for the next available slot using double hashing. Returns the first index found. Double
	hashing algorithm was reviewed at: http://faculty.cs.niu.edu/~freedman/340/340notes/340hash.htm*/
	int HashTable<T>::probe(int home, int key) {
		int jump = (HASHPRIME - (key % HASHPRIME)),
			index = (jump+home)%MAXHASH;
		return index;
	}

	/*Assign key and value at index(row) in both table and data vectors.*/
	bool HashTable<T>::create(int index, int key, T value, int collisions) {
		table[index] = Record<T>(key, value);
		size++; 
		return true;
	}
};

