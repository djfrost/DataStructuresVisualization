#include <iostream>
#include "DataStructures/HashTable.h"
using namespace std;

void hashTableDriver(){
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
}

int main(){
	bool running=true;
	string structureName;
	while(running){
		cout << "Which data structure do you want to use?" << endl;
		cout << "HashTable" << endl << "Exit" << endl;
		getline (cin,structureName);
		if (structureName == "HashTable"){
			hashTableDriver();
		}
		else if(structureName == "Exit"){
			running = false;
		}
		else{
			cout << "Please select a valid option" << endl;
		}
		cout << endl << endl; 
	}
	return 0;
}
