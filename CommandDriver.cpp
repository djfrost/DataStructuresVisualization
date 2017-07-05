#include <iostream>
#include "DataStructures/HashTable.h"
#include "DataStructures/Stack.h"
using namespace std;

void HashTableDriver(){
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
void StackDriver(){
	cout << "Constructing Stack" << endl;
	Stack<int>* stack = new Stack<int>();
	cout << "Pushing 26, 25, 24" << endl;
	int* temp = new int();
	*temp = 26;
	stack->Push(temp);
	temp = new int();
	*temp = 25;
	stack->Push(temp);
	temp = new int();
	*temp = 24;
	cout << "Popping ints of values are: ";
	stack->Push(temp);
	temp = stack->Pop();
	cout << *temp << ", ";
	delete temp;
	temp = stack->Pop();
	cout << *temp << ", ";
	delete temp;
	temp = stack->Pop();
	cout << *temp << endl;
	delete temp;
}
int main(){
	bool running=true;
	string structureName;
	while(running){
		cout << "Which data structure do you want to use?" << endl;
		cout << "HashTable" << endl <<  "Stack" << endl << "Exit" << endl;
		getline (cin,structureName);
		if (structureName == "HashTable"){
			HashTableDriver();
		}
		else if(structureName == "Stack"){
			StackDriver();
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
