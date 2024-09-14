#pragma once

class Stack {
public:
	Stack();
	~Stack();
	void push(int valorGenerico);
	int pop();
	bool empty();
	int size();
	void clear();
	int top();


private:
	struct StackNode
	{
		int valorGenerico;
		StackNode* proximoPilha;
	};

	int contador;
	StackNode* topoPilha;
};