#include "list.hpp"

#include <sstream>
#include <fmt/core.h>

template<typename T>
DoubleList<T>::DoubleList(T in_val) : size(1) {
    this->head = std::make_shared<Node>();

    // Head doesn't have previous
    head->previous = nullptr;
    head->value = in_val;
    head->next = nullptr;

    // All point to the same Node in the beginning
    current = tail = head;
}

template<typename T>
uint16_t DoubleList<T>::getSize() const {
    return size;
}

template<typename T>
void DoubleList<T>::InsertFront(T val)
{
    current = head;
    current->previous = std::make_shared<Node>();
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
void DoubleList<T>::InsertAfter(T val, size_t idx)
{
    if (idx >= this->getSize())
        { throw std::out_of_range(fmt::format("ERROR: Index {} overflowing list", idx)); }
    else if(idx == this->getSize() - 1)
    {
        this->InsertBack(val);
        return;
    }

    auto in_node = std::make_shared<Node>();
    in_node->value = val;

    MoveCurrent(idx);
    in_node->next = current->next;
    in_node->previous = current;
    in_node->next->previous = in_node;
    current->next = in_node;

    ++size;  
}

template<typename T>
void DoubleList<T>::InsertBefore(T val, size_t idx)
{
    if (idx >= this->getSize())
        { throw std::out_of_range(fmt::format("ERROR: Index {} overflowing list", idx)); }
    else if (idx == 0)
    {
        this->InsertFront(val);
        return;
    }

    auto in_node = std::make_shared<Node>();
    in_node->value = val;

    MoveCurrent(idx);
    in_node->previous = current->previous;
    in_node->next = current;
    in_node->previous->next = in_node;
    current->previous = in_node;

    ++size;
    
}

template<typename T>
void DoubleList<T>::MoveCurrent(size_t idx)
{
    // If we want to add in the front half of the list
    if (idx <= this->getSize() / 2)
    {
        current = head;
        for (size_t i = 0; i < idx; ++i)
        {
            current = current->next;
        } 
    }
    else // or the back half
    {
        current = tail;
        for (size_t i = this->getSize() - 1; i > idx; --i)
        {
            current = current->previous;
        }
    }
}

template<typename T>
int DoubleList<T>::Find(T val)
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
int DoubleList<T>::Delete(T val)
{
    if (this->Find(val) == -1)
        return -1;
    current = head;
    size_t counter = 0;
    while(current)
    {
        if (current->value == val)
        {
            if (current != head)
                { current->previous->next = current->next; }
            else
                { head = current->next; }
            if (current != tail)
                { current->next->previous = current->previous; }
            else
                { tail = current->previous; }
            ++counter;
            --size;
        }
        current = current->next;
    }
    return counter;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, DoubleList<T>& list)
{
    list.current = list.head;
    stream << "[ ";
    while(list.current)
    {
        if (list.current == list.head)
            { stream << list.current->value; }
        else 
            { stream << " -> " << list.current->value; }
        list.current = list.current->next;
    }
    stream << " ]";
    return stream;
}
