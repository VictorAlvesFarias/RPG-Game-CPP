#pragma once

class Fila {
public:
	Fila();
	~Fila();
	bool append(int genérico); //retorna se deu certo?
	int serve();
	bool empty();
	bool full();
	int size();
	void clear();
	int front();
	int rear();

private:
	struct NodeFila
	{
		int valorGenerico;
		NodeFila* proximoFila;
	};
	
	int contador;
	NodeFila* head;
	NodeFila* tail;
};