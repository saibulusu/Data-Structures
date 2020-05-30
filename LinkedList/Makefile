CXX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
ArrayList.o: LinkedList.cpp
clean:
	-rm LinkedList.o
	-rm demo
build: LinkedList.cpp LinkedList.o
	$(CXX) $(CXXFLGAS) -o demo Test.cpp LinkedList.o -lgtest -lgtest_main -pthread
