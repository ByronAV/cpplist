#pragma once

#include <memory>
#include <string>

// Forward declare both templates:
template <typename T> class DoubleList;
template <typename T> std::ostream& operator<<( std::ostream&, DoubleList<T>& );

template<typename T>
class DoubleList {
private:
    struct Node {
        std::shared_ptr<Node> previous;
        T value;
        std::shared_ptr<Node> next;
    };
public:
    // Constructors
    DoubleList() = delete;
    DoubleList(T in_value);

    // Destructor
    ~DoubleList() = default;

    // Insert a value at the front of the list
    void InsertFront(T val);

    // Insert a value at the back of the list
    void InsertBack(T val);

    // Insert value *after* the Node[idx]
    void InsertAfter(T val, size_t idx);

    // Insert value *before* the Node[idx]
    void InsertBefore(T val, size_t idx);

    // Delete a value from the list
    // @return the number of items removed or -1 if no items were removed
    int Delete(T val);

    // Find the first occurance of a value in the list
    // @return: the index in the list or -1 if not in the list
    int Find(T val);

    // Return size of list
    uint16_t getSize() const;

    void MoveCurrent(size_t idx);

    friend std::ostream& operator<< <T>(std::ostream& stream, DoubleList<T>& list);
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    std::shared_ptr<Node> current;
    uint16_t size;
};
