#include "IQueue.h"
#include <iostream>
using namespace std;

Fila::Fila() {
	contador = 0;
	head = NULL;
	tail = NULL;
}

Fila::~Fila() {

}

bool Fila::append(valor) {
	NodeFila* nodeInsercao;
	nodeInsercao = new NodeFila;

	if (nodeInsercao == NULL) {
		cout << "Não foi possível alocar dinâmicamente outro nó" << endl;
		abort();
	}

	nodeInsercao->valorGenerico = valor;
	nodeInsercao->proximoFila = NULL;

	if (head == NULL) {
		head = nodeInsercao;
		tail = nodeInsercao;
	}
	else {
		tail->proximoFila = nodeInsercao;
		tail = nodeInsercao
	}
	contador++;
	return true; //retorno necessário?
}

int Fila::serve() {
	int valorNode;
	valorNode = head->valorGenerico;

	NodeFila* auxiliar;

	auxiliar = head
		head = head->proximoFila;

	delete auxiliar;
	contador--;
	return valorNode;
}

int Fila::front() {
	return head->valorGenerico;
}

int Fila::rear() {
	return tail->valorGenerico;
}

void Fila::clear() {
	NodeFila* auxiliar;
	for (int i = 0; i >= contador; i++) {
		auxiliar = head;
		head = head->proximoFila;
		delete auxiliar;
	}
}
