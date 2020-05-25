CXX=g++ -std=c++11
CXXFLAGS=-Wall
INCLUDE = -I/usr/include/
LIBPATH = -L/usr/lib

all:build
ArrayList.o: ArrayList.cpp
clean:
	-rm ArrayList.o
	-rm demo
build: ArrayList.cpp ArrayList.o
	$(CXX) $(CXXFLGAS) -o demo Test.cpp ArrayList.o -lgtest -lgtest_main -pthread