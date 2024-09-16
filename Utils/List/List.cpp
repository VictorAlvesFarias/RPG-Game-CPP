#include "IList.h"
#include <iostream>
#include <functional> // Necessário para std::function
using namespace std;

template <typename T>
List<T>::List()
{
    Head = nullptr;
    Count = 0;
}

template <typename T>
List<T>::~List()
{
    ListNode *tempPointer;
    while (Head != nullptr)
    {
        tempPointer = Head;
        Head = Head->NextNode;
        delete tempPointer;
    }
}

template <typename T>
bool List<T>::IsEmpty()
{
    return Count == 0;
}

template <typename T>
bool List<T>::Insert(int index, T item)
{
    index++;

    if (index < 1 || index > Count + 1)
    {
        cout << "Insert error: Invalid index." << endl;
        abort();
    }

    ListNode *newNode = new ListNode;

    if (newNode == nullptr)
    {
        cout << "Unable to allocate memory for new node." << endl;
        abort();
    }

    newNode->Entry = item;

    if (index == 1)
    {
        newNode->NextNode = Head;
        Head = newNode;
    }
    else
    {
        ListNode *aux;
        SetPosition(index - 1, aux);
        newNode->NextNode = aux->NextNode;
        aux->NextNode = newNode;
    }

    Count++;

    return true;
}

template <typename T>
bool List<T>::Push(T item)
{
    Insert(Count, item);

    return true;
}

template <typename T>
int List<T>::Size()
{
    return Count;
}

template <typename T>
bool List<T>::Delete(int index)
{
    index++;
    if (index < 1 || index > Count)
    {
        cout << "Delete error: Invalid index." << endl;
        abort();
    }

    T item;
    ListNode *aux;
    if (index == 1)
    {
        aux = Head;
        item = aux->Entry;
        Head = Head->NextNode;
        delete aux;
    }
    else
    {
        ListNode *auxDelete;
        SetPosition(index - 1, auxDelete);
        aux = auxDelete->NextNode;
        item = aux->Entry;
        auxDelete->NextNode = aux->NextNode;
        delete aux;
    }
    Count--;

    return true;
}

template <typename T>
void List<T>::SetPosition(int index, ListNode *&current)
{
    current = Head;
    for (int i = 1; i < index; i++)
    {
        current = current->NextNode;
    }
}

template <typename T>
void List<T>::Clear()
{
    ListNode *temp;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->NextNode;
        delete temp;
    }
    Count = 0;
}

template <typename T>
void List<T>::Replace(T item, int index)
{
    index++;
    if (index < 1 || index > Count)
    {
        cout << "Replace error: Invalid index." << endl;
        abort();
    }

    ListNode *node;
    SetPosition(index, node);
    node->Entry = item;
}

template <typename T>
T List<T>::Get(int index)
{
    index++;
    if (index  < 1 || index > Count)
    {
        cout << "Get error: Invalid index." << endl;
        abort();
    }

    ListNode *node;
    SetPosition(index , node);

    return node->Entry;
}

template <typename T>
void List<T>::ForEach(function<void (T)> callback)
{
    for (int i = 0; i < Count; i++)
    {
        callback(Get(i));
    }
}