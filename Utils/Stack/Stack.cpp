#include "IStack.h"
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack()
{
	TopNode = nullptr;
	Counter = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}

template <typename T>
void Stack<T>::Push(T genericValue)
{
	StackNode *tempNode = new StackNode;

	if (tempNode == nullptr)
	{
		cout << "Unable to allocate memory for a new node." << endl;
		abort();
	}

	tempNode->NextNode = TopNode;
	tempNode->GenericValue = genericValue;
	TopNode = tempNode;
	Counter++;
}

template <typename T>
T Stack<T>::Pop() {

	if (IsEmpty()) {
		cout << "The stack has no elements" << endl;
		abort();
	}
;
	StackPointer p = top;
	top = top->NextNode;

	delete p;

	return 	TopNode->GenericValue;
}

template <typename T>
void Stack<T>::Clear() {

	while (!IsEmpty()) {
		Pop(x);
	}

}
template <typename T>
int Stack<T>::Size() {
	return Counter;
}
template <typename T>
bool Stack<T>::IsEmpty() {
	return TopNode == NULL;
}

template <typename T>
T Stack<T>::Top() {
	return TopNode->GenericValue
}

