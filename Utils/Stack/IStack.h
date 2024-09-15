#pragma once
template <typename T>
class Stack {
public:
	Stack();
	~Stack();
	void push(T valorGenerico);
	int pop();
	bool empty();
	int size();
	void clear();
	int top();


private:
	struct StackNode
	{
		T valorGenerico;
		StackNode* proximoPilha;
	};

	int contador;
	StackNode* topoPilha;
};