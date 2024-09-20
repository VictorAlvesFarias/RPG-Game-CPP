#include <iostream>
#include "IQueue.h"

using namespace std;

template <typename T>
Queue<T>::Queue()
{
    Counter = 0;
    Head = nullptr;
    Tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    Clear();
}

template <typename T>
bool Queue<T>::Append(T genericValue)
{
    QueueNode *newNode = new QueueNode;

    if (newNode == nullptr)
    {
        throw bad_alloc("Unable to allocate a new node for the Queue");
    }

    newNode->GenericValue = genericValue;
    newNode->NextNode = nullptr;

    if (Head == nullptr)
    {
        Head = newNode;
        Tail = newNode;
    }
    else
    {
        Tail->NextNode = newNode;
        Tail = newNode;
    }
    Counter++;
    return true;
}

template <typename T>
T Queue<T>::Serve()
{
    if (Head == nullptr)
    {
        throw out_of_range("The queue is empty.");
    }

    T nodeValue = Head->GenericValue;
    QueueNode *temp = Head;
    Head = Head->NextNode;

    delete temp;
    Counter--;
    return nodeValue;
}

template <typename T>
T Queue<T>::Front()
{
    if (Head == nullptr)
    {
        throw out_of_range("The queue is empty.");
    }
    return Head->GenericValue;
}

template <typename T>
T Queue<T>::Rear()
{
    if (Tail == nullptr)
    {
        throw out_of_range("The queue is empty.");
    }
    return Tail->GenericValue;
}

template <typename T>
void Queue<T>::Clear()
{
    while (Head != nullptr)
    {
        QueueNode *temp = Head;
        Head = Head->NextNode;
        delete temp;
    }
    Counter = 0;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return Counter == 0;
}

template <typename T>
int Queue<T>::Size()
{
    return Counter;
}

template <typename T>
bool Queue<T>::IsFull()
{
    return false; // No fixed size, so it's never full
}
