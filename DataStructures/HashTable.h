#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
/*
	Note: The current version does not support chaining. Collisions
	at this point in time are being ignored. In a future push this
	will be taken care of.
*/
/*
	HashEntry:
		Represents a key, value pair. Keys are in the form of strings,
		and values can be in the form of any data type. Note that the
		value must be a pointer.
*/
template<class T>
class HashEntry{
	public:
		HashEntry(std::string key, T* value){this->key = key; this->value = value;};
		~HashEntry(){delete value;};
		std::string GetKey(){return key;};
		T* GetValue(){return value;};
	private:
		std::string key;
		T* value;

};
/*
	HashTable:
		A basic HashTable data structure that allows us to specify size,
		and what type of data we are storing. All keys are in the form of
		ascii strings, and the hashing function evaluates a summation over
		the characters from the key.
*/
template<class T>
class HashTable{
	public:
		HashTable(int size=128);
		~HashTable();
		int Insert(std::string key, T* value);
		T* Retrieve(std::string key);
	private:
		HashEntry<T>** table;
		int Hash(std::string origKey);
		int size;
};
template<class T> HashTable<T>::HashTable(int size){
	table = new HashEntry<T>*[size];
	this->size = size;
}
template<class T> HashTable<T>::~HashTable(){
	for(int i =0; i < this->size; i++){
		if(table[i] != NULL){
			delete table[i];
		}
	}
	delete table;
}
template <class T> int HashTable<T>::Insert(std::string key, T* value){
	int index = Hash(key);
	HashEntry<T>* hEntry = new HashEntry<T>(key, value);
	table[index] = hEntry;
	return index;
}
template <class T> int HashTable<T>::Hash(std::string origKey){
	int currHash=0;
	int currMult = 1;
	for(int i=0; i<origKey.length(); i++){
		currHash += origKey.at(i) * currMult;
		currMult *= 256;
	}
	//Ensure we are inside the bounds of the array
	currHash=currHash%this->size;
	return currHash;
}
template <class T> T* HashTable<T>::Retrieve(std::string origKey){
	int index = Hash(origKey);
	return table[index]->GetValue();
}
#endif
