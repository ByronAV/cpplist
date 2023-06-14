#include <catch2/catch_test_macros.hpp>
#include "list.tpp"

TEST_CASE("Size Tests for Double Linked List", "[size]") {
    DoubleList<int> list(5);
    REQUIRE(list.getSize() == 1);

    list.InsertBack(89);
    list.InsertBack(90);
    list.InsertBack(50);

    list.Delete(90);
    REQUIRE(list.getSize() == 3);
}

TEST_CASE("Insert Front Test", "[IF]") {
    DoubleList<int> list(5);

    list.InsertFront(67);
    list.InsertFront(56);
    list.InsertFront(-98);

    REQUIRE(list.getSize() == 4);
    std::stringstream ss;
    ss << list;
    REQUIRE("[ -98 -> 56 -> 67 -> 5 ]" == ss.str());
}

TEST_CASE("Insert Back Test", "[IBa]") {
    DoubleList<int> list(5);

    list.InsertBack(67);
    list.InsertBack(56);
    list.InsertBack(-98);

    REQUIRE(list.getSize() == 4);
    std::stringstream ss;
    ss << list;
    REQUIRE("[ 5 -> 67 -> 56 -> -98 ]" == ss.str());
}

TEST_CASE("Insert After Test", "[IA]") {
    DoubleList<int> list(5);

    REQUIRE_THROWS(list.InsertAfter(2, -7));
    REQUIRE_THROWS(list.InsertAfter(2, 78));

    REQUIRE_NOTHROW(list.InsertAfter(2, 0));
    REQUIRE_NOTHROW(list.InsertAfter(2, 1));
}

TEST_CASE("Insert Before Test", "[IBe]") {
    DoubleList<int> list(5);

    REQUIRE_THROWS(list.InsertBefore(2, -7));
    REQUIRE_THROWS(list.InsertAfter(2, 78));

    REQUIRE_NOTHROW(list.InsertAfter(2, 0));
    REQUIRE_NOTHROW(list.InsertAfter(2, 1));
}

TEST_CASE("Find Test", "[F]") {
    DoubleList<int> list(5);

    for(int i = 0; i < 50; ++i)
        list.InsertBack(i);
    
    REQUIRE(list.Find(6) == 0);
    REQUIRE(list.Find(45) == 0);
    REQUIRE(list.Find(51) == -1);
}

TEST_CASE("Delete Test", "[D]") {
    DoubleList<int> list(5);

    for(int i = 0; i < 50; ++i)
        list.InsertBack(i);

    REQUIRE(list.getSize() == 51);

    list.Delete(5);
    list.Delete(34);
    list.Delete(35);
    REQUIRE(list.getSize() == 47);
    REQUIRE(list.Delete(78) == -1);
}