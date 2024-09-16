#pragma once
template <typename T>
class Stack {
    private: struct StackNode {
        T GenericValue;
        StackNode* NextNode;
    };

    private: int Counter;
    private: StackNode* TopNode;

    public: Stack();
    public: ~Stack();
    
    public: void Push(T genericValue);
    public: int Pop();
    public: bool IsEmpty();
    public: int Size();
    public: void Clear();
    public: int Top();
};
