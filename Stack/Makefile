CXX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
Stack.o: Stack.cpp
clean:
	-rm Stack.o
	-rm demo
build: Stack.cpp Stack.o
	$(CXX) $(CXXFLGAS) -o demo Test.cpp Stack.o -lgtest -lgtest_main -pthread