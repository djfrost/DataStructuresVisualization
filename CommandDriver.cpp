#include <iostream>
#include "DataStructures/HashTable.h"
using namespace std;
int main(){
	cout << "Constructing HashTable" << endl;
	HashTable<int>* hash = new HashTable<int>();
	int* temp = new int();
	*temp = 26;
	int helloIndex = hash->Insert("Hello", temp);
	cout << "Hello was stored at index " << helloIndex << endl;
	temp = hash->Retrieve("Hello");
	cout << "Retrieved " << *temp << endl;
	cout << "Deleting HashTable" << endl;
	delete hash;
	return 0;
}
