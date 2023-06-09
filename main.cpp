#include <iostream>
#include "list.tpp"

int main(void) {
    try{
    // Main for testing now
    DoubleList<int> list(5);
    list.InsertBack(6);
    list.InsertFront(9);
    list.InsertBack(8);
    list.InsertFront(10);
    list.InsertBack(9);
    std::cout << list << std::endl;
    list.InsertAfter(3, 2);
    std::cout << list << std::endl;
    list.InsertAfter(4, 5);
    std::cout << list << std::endl;
    list.InsertBefore(56, 0);
    std::cout << list << std::endl;
    list.InsertBefore(99, 8);
    std::cout << list << std::endl;
    list.Delete(10);
    std::cout << list << std::endl;
    list.Delete(9);
    std::cout << list << std::endl;
    list.Delete(56);
    std::cout << list << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
