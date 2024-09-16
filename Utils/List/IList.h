#pragma once

template <typename T>
class List {
    private :int Count;
    private :ListNode* Head;

    public: List();
    public: ~List();
    public: bool IsEmpty();
    public: void Insert(int index, T genericValue);
    public: int Delete(int index);
    public: int Size();
    public: void Clear();
    public: T Retrieve(int index);
    public: void ForEach(std::function<void(T)> callback);
    public: void Replace(T genericValue, int index);

    private :struct ListNode {
        T Entry;
        ListNode* NextNode;
    };

    private :void SetPosition(int index, ListNode*& current);
};
