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
		cout << "N�o foi poss�vel alocar um novo n�":
		abort();
	}

	auxiliar->proximoPilha = NULL;
	auxiliar->valorGenerico = valorGenerico;

	if (topoPilha == NULL) {
		topoPilha = auxiliar
	}
}