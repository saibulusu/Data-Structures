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
        list = new LinkedList<int>;
    }

    virtual void TearDown() {
        delete list;
    }

    LinkedList<int>* list;
};

/** Check the size of an empty list */
TEST_F(LinkedListTest, SizeNoElements) {
    try {
        int size = list->getSize();
        ASSERT_EQ(size, 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check the size after inserting a few values */
TEST_F(LinkedListTest, InsertFewSize) {
    try {
        list->insert(0);
        list->insert(-1);
        list->insert(-100);
        list->insert(200);
        int size = list->getSize();
        ASSERT_EQ(size, 4);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Insert a few values and then check the value at the end */
TEST_F(LinkedListTest, InsertCheckValue) {
    try {
        list->insert(0);
        list->insert(-1);
        list->insert(10);
        list->insert(4);
        int val = list->get(3);
        ASSERT_EQ(val, 4);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Get an element from an empty list */
TEST_F(LinkedListTest, GetEmpty) {
    try {
        int doesnotexist = list->get(0);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Getting out of bounds");
    }
}

/** Alter an empty list */
TEST_F(LinkedListTest, AlterEmpty) {
    try {
        int doesnotexist = list->alter(2, 100);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Altering out of bounds");
    }
}

/** Alter with a negative index */
TEST_F(LinkedListTest, AlterNegative) {
    try {
        int doesnotexist = list->alter(-2, 100);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Altering out of bounds");
    }
}

/** Removing from an empty list */
TEST_F(LinkedListTest, RemoveEmpty) {
    try {
        int doesnotexist = list->remove(2);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Removing out of bounds");
    }
}

/** Insert and remove in alternate fashion then check size */
TEST_F(LinkedListTest, InsertRemoveAlternateSize) {
    try {
        list->insert(0);
        int a = list->remove(0);
        list->insert(100);
        int b = list->remove(0);
        list->insert(99);
        int size = list->getSize();
        ASSERT_EQ(size, 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Insert and remove in alternate fashion then check any value */
TEST_F(LinkedListTest, InsertRemoveAlternateValue) {
    try {
        list->insert(-100);
        list->insert(3030);
        list->insert(-1000);
        int b = list->remove(0);
        int val = list->get(0);
        ASSERT_EQ(val, 3030);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Insert at 0 to an empty list */
TEST_F(LinkedListTest, InsertAtZeroEmptySize) {
    try {
        list->insert(0, 100);
        int size = list->getSize();
        ASSERT_EQ(size, 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Insert a few values then check inserting at an index */
TEST_F(LinkedListTest, InsertFewInsertAtIndexValue) {
    try {
        list->insert(0, 100);
        list->insert(0, 200);
        list->insert(0, 300);
        int val = list->get(2);
        ASSERT_EQ(val, 100);
    } catch (std::exception& e) {
        FAIL();
    }
}

// Run the tests
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
