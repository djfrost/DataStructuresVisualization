#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
/*
	Stack:
		A basic Stack data structure that supports resizing.
		Note that stacks are LIFO.
*/
template <typename T>
struct StackNode
{
  T* data;
  StackNode<T> * lastNode;
};

template<class T>
class Stack{
	public:
		Stack();
		~Stack();
		void Push(T* item);
		T* Pop();
		int GetSize();
	private:
		StackNode<T>* topItem;
		int size;
};
//Initialize the stack. By making the topItem null we will know where to stop popping from
template<class T> Stack<T>::Stack(){
	topItem = NULL;
	//No items yet
	size=0;
}
template<class T> Stack<T>::~Stack(){
	T* top = this->pop();
	while(top != NULL){
		delete top->data;
		delete top;
		top = this->pop();
	}
}
template<class T> void Stack<T>::Push(T* item){
	StackNode<T>* newTop = new StackNode<T>();
	newTop->data = item;
	newTop->lastNode = topItem;
	topItem = newTop;
}
template<class T> T* Stack<T>::Pop(){
	T* top = topItem->data;
	StackNode<T>* next = topItem->lastNode;
	delete topItem;
	topItem = next;
	return top;
}
#endif
