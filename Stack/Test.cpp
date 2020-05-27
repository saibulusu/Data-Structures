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
        stack = new Stack<std::string>;
    }

    virtual void TearDown() {
        delete stack;
    }

    Stack<std::string>* stack;
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
        std::string elementDoesNotExist = stack->peek();
        FAIL();
    } catch (std::exception& e) {
        ASSERT_EQ(e.what(), "Peeking out of bounds");
    }
}

/** Insert 2 elements and peek */
TEST_F(StackTest, PeekAfterInsert) {
    try {
        stack->push("");
        stack->push("to be peeked");
        std::string peeker = stack->peek();
        char top[peeker.size() + 1];
        strcpy(top, peeker.c_str());
        ASSERT_STREQ(top, "to be peeked");
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Push 2 elements and check size **/
TEST_F(StackTest, PushCheckSize) {
    try {
        stack->push("");
        stack->push("this is a new string");
        ASSERT_EQ(stack->getSize(), 2);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Push 5 elements and pop 2 elements and check the size **/
TEST_F(StackTest, PushPopCheckSize) {
    try {
        stack->push("");
        stack->push("ignore");
        stack->push("ignore this string");
        stack->push("fourth element");
        stack->push("10000");
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
        stack->push("first");
        stack->pop();
        stack->push("");
        stack->pop();
        stack->push("string");
        stack->pop();
        ASSERT_EQ(stack->getSize(), 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Alternate push and pop and pop and return pop **/
TEST_F(StackTest, AlternatePushPopReturnValue) {
    try {
        stack->push("");
        stack->pop();
        stack->push("first");
        stack->pop();
        stack->push("second");
        stack->push("");
        std::string empty = stack->pop();
        char array[empty.size() + 1];
        strcpy(array, empty.c_str());
        ASSERT_STREQ(array, "");
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Run the program **/
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}