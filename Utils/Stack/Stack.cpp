#include "IStack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
	topoPilha = NULL;
	contador = 0;
}

Stack::~Stack() {

}

void Stack::push(int valorGenerico) {
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