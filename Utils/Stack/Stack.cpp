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
        cout << "Memory allocation failed" << endl;
	}

	tempNode->NextNode = TopNode;
	tempNode->GenericValue = genericValue;
	TopNode = tempNode;

	Counter++;
}

template <typename T>
T Stack<T>::Pop() {

	if (IsEmpty()) {
        cout << "Memory allocation failed" << endl;
	};
	
	StackNode* p = TopNode;
	T response = TopNode->GenericValue;
	TopNode = TopNode->NextNode;

	Counter--;
	
	delete p;
	
	return response;
}

template <typename T>
void Stack<T>::Clear() {

	while (!IsEmpty()) {
		Pop();
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
	return TopNode->GenericValue;
}