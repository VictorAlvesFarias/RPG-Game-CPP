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
	Clear(); // Adicionado para liberar a memória corretamente, caso necessário
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
