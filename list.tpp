#include "list.hpp"

#include <sstream>

template<typename T>
DoubleList<T>::DoubleList(T in_val) : size(1) {
    this->head = std::make_unique<Node>();

    // Head doesn't have previous
    head->previous = nullptr;
    head->value = in_val;
    head->next = nullptr;

    // All point to the same Node in the beginning
    current = tail = head;
}

template<typename T>
DoubleList<T>::~DoubleList() {}

template<typename T>
uint16_t DoubleList<T>::getSize() const {
    return size;
}

template<typename T>
void DoubleList<T>::InsertFront(T val)
{
    current = head;
    current->previous = std::make_unique<Node>();
    current->previous->previous = nullptr;
    current->previous->value = val;
    current->previous->next = current;
    head = current->previous;
    ++size;
}

template<typename T>
void DoubleList<T>::InsertBack(T val)
{
    current = tail;
    current->next = std::make_unique<Node>();
    current->next->previous = current;
    current->next->value = val;
    current->next->next = nullptr;
    tail = current->next;
    ++size;
}

template<typename T>
size_t DoubleList<T>::Find(T val)
{
    current = head;
    size_t i = 0;
    while(current)
    {
        if (current->value == val)
            { return i; }
        current = current->next;
    }
    return -1;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, DoubleList<T>& list)
{
    list.current = list.head;
    stream << "[ ";
    while(list.current)
    {
        stream << list.current->value << " ";
        list.current = list.current->next;
    }
    stream << "]";
    return stream;
}
