#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "Queue.cpp"

/** Fixture Class **/
class QueueTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        queue = new Queue<int>;
    }

    virtual void TearDown() {
        delete queue;
    }

    Queue<int>* queue;
};

/** Assert that the size of an empty queue is 0 */
TEST_F(QueueTest, EmptySize){
    try {
        ASSERT_EQ(queue->getSize(), 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}