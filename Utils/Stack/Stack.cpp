#include "IStack.h"
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack() {
	topoPilha = NULL;
	contador = 0;
}

template <typename T>
Stack<T>::~Stack() {

}
template <typename T>
void Stack<T>::push(T valorGenerico) {
	StackNode* auxiliar;
	auxiliar = new StackNode;
	if (auxiliar == NULL) {
		cout << "N�o foi poss�vel alocar um novo n�";
		abort();
	}

	auxiliar->proximoPilha = topoPilha;
	auxiliar->valorGenerico = valorGenerico;
	topoPilha = auxiliar;
}