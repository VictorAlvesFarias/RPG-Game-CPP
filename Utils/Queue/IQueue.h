#pragma once

template <typename T>
class Queue {
    private: struct QueueNode {
        T GenericValue;
        QueueNode* NextNode;
    };

    private: int Counter;
    private: QueueNode* Head;
    private: QueueNode* Tail;

    public: Queue();
    public: ~Queue();

    public: bool Append(T genericValue); // Returns true if successful
    public: T Serve();
    public: bool IsEmpty();
    public: bool IsFull();
    public: int Size();
    public: void Clear();
    public: T Front();
    public: T Rear();
};
