#pragma once

class Pilha {
public:
	Pilha();
	~Pilha();
	void push(int valorGenerico);
	int pop();
	bool empty();
	int size();
	void clear();
	int top();


private:
	struct PilhaNode
	{
		int valorGenerico;
		PilhaNode* proximoPilha;
	};

	int contador;
	PilhaNode* topoPilha;
};