#include "IList.h"

#include <iostream>
using namespace std;

template <typename T>
List<T>::List() {
	head = NULL;
	contador = 0;
}
template <typename T>
List<T>::~List() {
	ListNode* ponteiroAux;
	while (head != NULL) {
		ponteiroAux = head;
		head = head->nextNode;
		delete ponteiroAux;
	}
}
template <typename T>
bool List<T>::empty() {
	return contador == 0;
}
template <typename T>
void List<T>::insert(int index, T valor) {
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
	newNode->entry = index;
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
template <typename T>

int List<T>::size() {
	return contador;
}
template <typename T>
int List<T>::Delete(int index) {
	if (index < 1 || index > contador) {
		cout << "num tem nada";
		abort();
	}
	T valorGenerico;
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

template <typename T>
void List<T>::setPosition(int index, ListNode*& atual) {
	atual = head; //se for null vai cair nas verificações feitas no insert e delete
	for (int i = 2; i <= index; i++) {
		atual = atual->nextNode;
	}
}
template <typename T>
void List<T>::clear() {
	ListNode* auxiliar;
	while (head != NULL) {
		auxiliar = head;
		head = head->nextNode;
		delete auxiliar;
	}
	contador = 0;
}
template <typename T>
void List<T>::replace(T valor, int index) {
	if (valor < 1 || valor > contador) {
		cout << "num pode" << endl;
		abort();
	}

	ListNode* node;
	setPosition(index, node);
	node->entry = index;

}
template <typename T>
int List<T>::retrieve(int index) {
	if (index < 1 || index > contador) {
		cout << "num pode" << endl;
		abort();
	}
	T valorGenerico;
	ListNode* node;
	setPosition(index, node);
	return valorGenerico = node->entry;
}