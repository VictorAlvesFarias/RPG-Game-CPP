#pragma once

template <typename T>

class List {
public:
	List();
	~List();
	bool empty();
	void insert(int index, T valorGenerico);
	int Delete(int index);
	int size();
	void clear();
	int retrieve(int index);
	void replace(T valorGenerico, int index);

private:
	struct ListNode {
		int entry;
		ListNode* nextNode;
	};
	int contador;
	ListNode* head;
	void setPosition(int index, ListNode*& atual);

};
