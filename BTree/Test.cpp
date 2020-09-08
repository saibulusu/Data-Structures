#include <stdio.h>
#include <iostream>
#include <exception>
#include <gtest/gtest.h>
#include <string>
#include "BTree.cpp"

/** Fixture Class */
class BTreeTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		tree = new BTree<int>();
	}

	virtual void TearDown() {
		delete tree;
	}

	BTree<int>* tree;
};

/** Run the program */
int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
