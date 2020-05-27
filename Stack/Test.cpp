#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "Stack.cpp"

/** Fixture Class **/
class StackTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        stack = new Stack<int>;
    }

    virtual void TearDown() {
        delete stack;
    }

    Stack<int>* stack;
};

/** Check the size when there are no elements **/
TEST_F(StackTest, SizeNoElements) {
    try {
        int size = stack->getSize();
        ASSERT_EQ(size, 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Peek into the Stack when there are no elements inserted **/
TEST_F(StackTest, PeekNoElements) {
    try {
        int elementDoesNotExist = stack->peek();
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Peeking out of bounds");
    }
}

/** Insert 2 elements and peek */
TEST_F(StackTest, PeekAfterInsert) {
    try {
        stack->push(0);
        stack->push(1);
        int element = stack->peek();
        ASSERT_EQ(stack->peek(), 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Push 2 elements and check size **/
TEST_F(StackTest, PushCheckSize) {
    try {
        stack->push(100);
        stack->push(-1);
        ASSERT_EQ(stack->getSize(), 2);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Push 5 elements and pop 2 elements and check the size **/
TEST_F(StackTest, PushPopCheckSize) {
    try {
        stack->push(-1000);
        stack->push(100);
        stack->push(0);
        stack->push(4);
        stack->push(5);
        stack->pop();
        stack->pop();
        ASSERT_EQ(stack->getSize(), 3);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Alternate push and pop and check size **/
TEST_F(StackTest, AlternatePushPopCheckSize) {
    try {
        stack->push(1);
        stack->pop();
        stack->push(0);
        stack->pop();
        stack->push(2);
        stack->pop();
        ASSERT_EQ(stack->getSize(), 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Alternate push and pop and pop and return pop **/
TEST_F(StackTest, AlternatePushPopReturnValue) {
    try {
        stack->push(0);
        stack->pop();
        stack->push(1);
        stack->pop();
        stack->push(2);
        stack->push(0);
        int empty = stack->pop();
        ASSERT_EQ(empty, 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Run the program **/
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}