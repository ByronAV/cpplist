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
    ~DoubleList();

    // Insert a value at the back of the list
    void InsertBack(T val);

    // Insert a value at the front of the list
    void InsertFront(T val);

    // Delete a value from the list
    void Delete(T val);

    // Find if value is in the list
    // @return: the index in the list
    size_t Find(T val);

    // Return size of list
    uint16_t getSize() const;

    friend std::ostream& operator<< <T>(std::ostream& stream, DoubleList<T>& list);
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    std::shared_ptr<Node> current;
    uint16_t size;
};
