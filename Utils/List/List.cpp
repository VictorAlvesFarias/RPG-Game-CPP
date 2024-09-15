#include "IList.h"
#include <iostream>
using namespace std;


List::List() {
	head = NULL;
	contador = 0;
}

List::~List() {
	ListNode* ponteiroAux;
	while (head != NULL) {
		ponteiroAux = head;
		head = head->nextNode;
		delete ponteiroAux;
	}
}

bool List::empty() {
	return contador == 0;
}

void List::insert(int valor, int index) {
	if (index < 1 || index > contador + 1) {
		cout << "num pode" << endl;
		abort();
	}

	ListNode* newNode;
	newNode = new ListNode;
	if (newNode == NULL) {
		cout << "num deu";
		abort();
	}
	newNode->entry = valor;
	if (index == 1) {
		newNode->nextNode = head;
		head = newNode;
	}
	else {
		ListNode* aux;
		setPosition(index - 1, aux);
		newNode->nextNode = aux->nextNode;
		head->nextNode = newNode;
	}
	contador++;

}


int List::size() {
	return contador;
}

int List::Delete(int index) {
	if (index < 1 || index > contador) {
		cout << "num tem nada";
		abort();
	}
	int valorGenerico;
	ListNode* aux;
	if (index == 1) {
		aux = head;
		valorGenerico = aux->entry;
		head = head->nextNode;
		delete aux;
		return valorGenerico;
	}
	else {
		ListNode* auxDelete;
		setPosition(index - 1, auxDelete);
		aux = auxDelete->nextNode;
		valorGenerico = aux->entry;
		delete auxDelete;
		return valorGenerico;
	}
}

void List::setPosition(int index, ListNode*& atual) {
	atual = head; //se for null vai cair nas verificações feitas no insert e delete
	for (int i = 2; i <= index; i++) {
		atual = atual->nextNode;
	}
}

void List::clear() {
	ListNode* auxiliar;
	while (head != NULL) {
		auxiliar = head;
		head = head->nextNode;
		delete auxiliar;
	}
	contador = 0;
}

void List::replace(int index, int valor) {
	if (index < 1 || index > contador) {
		cout << "num pode" << endl;
		abort();
	}

	ListNode* node;
	setPosition(index, node);
	node->entry = valor;

}

int List::retrieve(int index) {
	if (index < 1 || index > contador) {
		cout << "num pode" << endl;
		abort();
	}
	int valorGenerico;
	ListNode* node;
	setPosition(index, node);
	return valorGenerico = node->entry;
}