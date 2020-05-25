#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "ArrayList.cpp"

/** Fixture class **/
class ArrayListTest : public ::testing::Test {
    protected:
    virtual void SetUp() {
        array = new ArrayList<int>;
    }

    virtual void TearDown() {
        delete array;
    }

    ArrayList<int>* array;
};

/** Check the size of an ArrayList that has just been initialized **/
TEST_F(ArrayListTest, InitSize) {
    ASSERT_EQ(array->getSize(), 0);
}

/** Get an element in the ArrayList with no elements **/
TEST_F(ArrayListTest, GetNoElements) {
    try {
        int elementDoesNotExist = array->get(0);
       FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Accessing out of bounds");
    }
}

/** Get the first element in the ArrayList after inserting a few values **/
TEST_F(ArrayListTest, GetAfterInsert) {
    try {
        array->insert(2);
        array->insert(3);
        array->insert(-1);        
    } catch (std::exception& e) {
        FAIL();
    }
    ASSERT_EQ(array->get(0), 2);
}

/** Check the size after inserting a small number of elements **/
TEST_F(ArrayListTest, GetSizeAfterInsert) {
    try {
        array->insert(10);
        array->insert(1);
    } catch (std::exception& e) {
        FAIL();
    }
    ASSERT_EQ(array->getSize(), 2);
}

/** Get an element out of bounds after inserting a few elements by going negative **/
TEST_F(ArrayListTest, GetOutOfRangeAfterInsertUnder) {
    try {
        array->insert(5);
        array->insert(2);
        array->insert(0);
        array->insert(-10);
        int elementDoesNotExist = array->get(-1);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Accessing out of bounds");
    }
}

/** Get an element out of bounds after inserting a few elements by going above the size **/
TEST_F(ArrayListTest, GetOutOfRangeAfterInsertOver) {
    try {
        array->insert(5);
        array->insert(2);
        array->insert(0);
        array->insert(-10);
        int elementDoesNotExist = array->get(4);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Accessing out of bounds");
    }
}

/** Get the last element after inserting a few elements **/
TEST_F(ArrayListTest, GetLastAfterInserting) {
    try {
        array->insert(0);
        array->insert(-1);
        array->insert(1);
        array->insert(-2);
        array->insert(2);
        array->insert(5);
    } catch (std::exception& e) {
        FAIL();
    }
    ASSERT_EQ(array->get(5), 5);
}

/** Keep inserting at the beginning and check **/
TEST_F(ArrayListTest, InsertAtBeginning) {
    try {
        array->insert(0, 0);
        array->insert(0, -1);
    } catch (std::exception& e) {
        FAIL();
    }
    ASSERT_EQ(array->get(0), -1);
}

/** Insert a value out of bounds **/
TEST_F(ArrayListTest, InsertingOutOfBounds) {
    try {
        array->insert(1, 0);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Inserting out of bounds");
    }
}

/** Insert at the beginning by index when there are no elements **/
TEST_F(ArrayListTest, InsertingAtHeadNoElements) {
    try {
        array->insert(0, 10);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Insert at a negative position **/
TEST_F(ArrayListTest, InsertNegative) {
    try {
        array->insert(-1, 1000);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Inserting out of bounds");
    }
}

/** Alter a value out of bounds negative**/
TEST_F(ArrayListTest, AlterNegative) {
    try {
        array->insert(111);
        int elementDoesNotExist = array->alter(-1, 100000);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Altering out of bounds");
    }
}

/** Alter a value out of bounds with no elements **/
TEST_F(ArrayListTest, AlterOutOfBoundsNoElements) {
    try {
        int elementDoesNotExist = array->alter(0, 100);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Altering out of bounds");
    }
}

/** Alter a value out of bounds over **/
TEST_F(ArrayListTest, AlterOutOfBoundsOver) {
    try {
        int elementDoesNotExist = array->alter(0, 1);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Altering out of bounds");
    }
}

/** Alter a value and check that it changed **/
TEST_F(ArrayListTest, AlterCheckValue) {
    try {
        array->insert(3);
        array->insert(2);
        array->insert(100);
        int oldElement = array->alter(1, 200);
        ASSERT_EQ(array->get(1), 200);
    } catch (std::exception& e) {
        FAIL();
    }
}

/**  Check the return value after altering a value **/
TEST_F(ArrayListTest, AlterReturnValue) {
    try {
        array->insert(0);
        array->insert(100);
        array->insert(200);
        array->insert(300);
        array->insert(400);
        int oldElement = array->alter(4, 500);
        ASSERT_EQ(oldElement, 400);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Alter a value and check other values are not changed **/
TEST_F(ArrayListTest, AlterOtherValues) {
    try {
        array->insert(-3);
        array->insert(-4);
        int oldElement = array->alter(1, -5);
        ASSERT_EQ(array->get(0), -3);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check what happens when removing from an empty ArrayList **/
TEST_F(ArrayListTest, RemoveNoElements) {
    try {
        int oldElement = array->remove(0);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Removing out of bounds");
    }
}

/** Insert a few elements and try to remove above the bounds **/
TEST_F(ArrayListTest, RemoveOutOfBoundsOver) {
    try {
        array->insert(40);
        array->insert(50);
        array->insert(1, 30);
        int oldElement = array->remove(3);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Removing out of bounds");
    }
}

/** Try to remove when there are no elements in the ArrayList **/
TEST_F(ArrayListTest, RemoveOutOfBoundsUnder) {
    try {
        array->insert(10);
        array->insert(5);
        array->insert(0);
        int oldElement = array->remove(-1);
        FAIL();
    } catch (std::exception& e) {
        ASSERT_STREQ(e.what(), "Removing out of bounds");
    }
}

/** Check the return value of returning from the ArrayList **/
TEST_F(ArrayListTest, RemoveReturnValue) {
    try {
        array->insert(0);
        array->insert(-1);
        array->insert(-10);
        int oldElement = array->remove(0);
        ASSERT_EQ(oldElement, 0);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Check the size of the ArrayList after removing a few elements **/
TEST_F(ArrayListTest, RemoveSize) {
    try {
        array->insert(0);
        array->insert(1);
        array->insert(10);
        array->remove(0);
        array->remove(0);
        ASSERT_EQ(array->getSize(), 1);
    } catch (std::exception& e) {
        FAIL();
    }
}

/** Run the program **/
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}