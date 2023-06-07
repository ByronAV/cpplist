#include <iostream>
#include "list.tpp"

int main(void) {
    // Main for checking now
    DoubleList<int> list(5);
    list.InsertBack(6);
    list.InsertFront(9);
    list.InsertBack(8);
    list.InsertFront(10);
    list.InsertBack(9);
    return 0;
}
