#pragma once
#include <functional> 
using namespace std;

template <typename T>
class List {
    private :struct ListNode {
        T Entry;
        ListNode* NextNode;
    };

    private :int Count;
    private :ListNode* Head;

    public: List();
    public: ~List();
    public: bool IsEmpty();
    public: bool Insert(int index, T genericValue);
    public: bool Push( T genericValue);
    public: bool Delete(int index);
    public: int Size();
    public: void Clear();
    public: T Get(int index);
    public: void ForEach(function<void(T,int)> callback);
    public: void ForEach(function<void(T)> callback);
    public: void Replace(T genericValue, int index);
    private :void SetPosition(int index, ListNode*& current);
};
