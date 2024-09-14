#include <iostream>
#include "IQueue.h"

using namespace std;

template <typename T>
Fila<T>::Fila() {
    contador = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
Fila<T>::~Fila() {
    clear();
}

template <typename T>
bool Fila<T>::append(T valorGenerico) {
    NodeFila* nodeInsercao = new NodeFila;

    if (nodeInsercao == nullptr) {
        cout << "Não foi possível alocar dinâmicamente outro nó" << endl;
        abort();
    }

    nodeInsercao->valorGenerico = valorGenerico;
    nodeInsercao->proximoFila = nullptr;

    if (head == nullptr) {
        head = nodeInsercao;
        tail = nodeInsercao;
    }
    else {
        tail->proximoFila = nodeInsercao;
        tail = nodeInsercao;
    }
    contador++;
    return true;
}

template <typename T>
T Fila<T>::serve() {
    if (head == nullptr) {
        throw std::out_of_range("A fila está vazia.");
    }

    T valorNode = head->valorGenerico;
    NodeFila* auxiliar = head;
    head = head->proximoFila;

    delete auxiliar;
    contador--;
    return valorNode;
}

template <typename T>
T Fila<T>::front() {
    if (head == nullptr) {
        throw std::out_of_range("A fila está vazia.");
    }
    return head->valorGenerico;
}

template <typename T>
T Fila<T>::rear() {
    if (tail == nullptr) {
        throw std::out_of_range("A fila está vazia.");
    }
    return tail->valorGenerico;
}

template <typename T>
void Fila<T>::clear() {
    while (head != nullptr) {
        NodeFila* auxiliar = head;
        head = head->proximoFila;
        delete auxiliar;
    }
    contador = 0;
}

template <typename T>
bool Fila<T>::empty() {
    return contador == 0;
}

template <typename T>
int Fila<T>::size() {
    return contador;
}

template <typename T>
bool Fila<T>::full() {
    return false; / 
}
