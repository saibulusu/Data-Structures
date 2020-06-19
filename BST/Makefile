CXX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
BST.o: BST.cpp
clean:
	-rm BST.o
	-rm demo
build: BST.cpp BST.o
	$(CXX) $(CXXFLGAS) -o demo Test.cpp BST.o -lgtest -lgtest_main -pthread
