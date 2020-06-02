CXX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
Queue.o: Queue.cpp
clean:
	-rm Queue.o
	-rm demo
build: Queue.cpp Queue.o
	$(CXX) $(CXXFLGAS) -o demo Test.cpp Queue.o -lgtest -lgtest_main -pthread