#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T> class HashTable {
#define MAXHASH 1000;
	
public:
	vector<vector<int>> table; // Stores our data : key, collisions
	vector<T> data; //Stores our data

	HashTable<T>::HashTable()
	{
		table.resize(MAXHASH, vector<int>(2, NULL));
		data.resize(MAXHASH, NULL);
	}

	HashTable<T>::~HashTable()
	{
	}

	bool HashTable<T>::insert(int key, T value, int& collisions) {
		int index = hash(key);

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

