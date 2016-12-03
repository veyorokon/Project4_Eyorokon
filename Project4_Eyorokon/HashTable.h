#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T> class HashTable {
#define MAXHASH 1000;
	
public:
	vector<vector <T>> table;


	HashTable()
	{
		table(MAXHASH, NULL);
	}

	~HashTable()
	{
	}
	bool HashTable<T>::insert(int key, T value, int& collisions) {

	}

	bool HashTable<T>::remove(int key) {

	}

	bool HashTable<T>::find(int key, T& value) {

	}

	float HashTable<T>::alpha() {

	}

	int HashTable<T>::hash(int key) {
		int index;

	}

	int HashTable<T>::probe() {

	}

};

