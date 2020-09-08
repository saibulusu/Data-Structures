XX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
BTree.o: BTree.cpp
clean:
    -rm BTree.o
    -rm demo
build: BTree.cpp BTree.o
    $(CXX) $(CXXFLGAS) -o demo Test.cpp Btree.o -lgtest -lgtest_main -pthread
