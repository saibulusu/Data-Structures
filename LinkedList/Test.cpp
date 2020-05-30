#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "LinkedList.cpp"           

/** Fixture class **/
class LinkedListTest : public ::testing::Test {
    protected:
    virtual void SetUp() {
        array = new LinkedList<int>;
    }

    virtual void TearDown() {
        delete array;
    }

    LinkedList<int>* array;
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
