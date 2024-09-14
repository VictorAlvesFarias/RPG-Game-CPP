#pragma once

template <typename T>
class Fila {
public:
    Fila();
    ~Fila();
    bool append(T valorGenerico); // Retorna se deu certo
    T serve();
    bool empty();
    bool full();
    int size();
    void clear();
    T front();
    T rear();

private:
    struct NodeFila {
        T valorGenerico;
        NodeFila* proximoFila;
    };

    int contador;
    NodeFila* head;
    NodeFila* tail;
};

