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

/** Check the first element from an empty queue */
TEST_F(QueueTest, EmptyPeek) {
    try {
        int val = queue->peek();
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Peeking out of bounds");
    }
}

/** Remove an element from an empty queue */
TEST_F(QueueTest, EmptyDequeue) {
    try {
        int doesnotexist = queue->dequeue();
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Dequeuing out of bounds");
    }
}

/** Enqueue and Dequeue once each and check the size is 0 */
TEST_F(QueueTest, EnqueueDequeueSize) {
    try {
        queue->enqueue(3);
        int three = queue->dequeue();
        ASSERT_EQ(queue->getSize(), 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check the value after enqueueing and dequeueing once each */
TEST_F(QueueTest, EnqueueDequeueValue) {
    try {
        queue->enqueue(190);
        int val = queue->dequeue();
        ASSERT_EQ(val, 190);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check the value after enqueueing multiple times and then deuqueing once */
TEST_F(QueueTest, MultiEnqueueOneDequeue) {
    try {
        queue->enqueue(-1);
        queue->enqueue(-2);
        queue->enqueue(-4);
        int val = queue->dequeue();
        ASSERT_EQ(val, -1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Enqueue multiple times then dequeue multiples times and check the size */
TEST_F(QueueTest, MultiEnqueueMultiDequeueSize) {
    try {
        queue->enqueue(-1);
        queue->enqueue(-4);
        queue->enqueue(1000);
        queue->enqueue(432);
        queue->dequeue();
        queue->dequeue();
        queue->dequeue();
        int size = queue->getSize();
        ASSERT_EQ(size, 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Enqueue once and then peek */
TEST_F(QueueTest, EnqueueOncePeek) {
    try {
        queue->enqueue(2);
        int val = queue->peek();
        ASSERT_EQ(val, 2);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check that peek does not change the size of the queue */
TEST_F(QueueTest, EnqueueOncePeekSize) {
    try {
        queue->enqueue(10);
        int val = queue->peek();
        int size = queue->getSize();
        ASSERT_EQ(size, 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}