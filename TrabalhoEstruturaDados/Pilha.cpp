#include "Pilha.h"
#include <iostream>
using namespace std;

Pilha::Pilha() {
	topoPilha = NULL;
	contador = 0;
}

Pilha::~Pilha() {

}

void Pilha::push(int valorGenerico) {
	PilhaNode* auxiliar;
	auxiliar = new PilhaNode;
	if (auxiliar == NULL){
		cout << "Não foi possível alocar um novo nó":
		abort();
	}

	auxiliar->proximoPilha = NULL;
	auxiliar->valorGenerico = valorGenerico;

	if (topoPilha == NULL) {
		topoPilha = auxiliar
	}
}