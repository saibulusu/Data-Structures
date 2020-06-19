#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "BST.cpp"

/** Fixture Class **/
class BSTTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        tree = new BST<int>;
    }

    virtual void TearDown() {
        delete tree;
    }

    BST<int>* tree;
};



/** Run the program **/
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
