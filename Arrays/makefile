CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

all: main

main: main.o dynamicArray.o testDynamicArray.o
	$(CXX) $(CXXFLAGS) -o main main.o dynamicArray.o testDynamicArray.o

main.o: main.cpp dynamicArray.h testDynamicArray.h
	$(CXX) $(CXXFLAGS) -c main.cpp

dynamicArray.o: dynamicArray.cpp dynamicArray.h
	$(CXX) $(CXXFLAGS) -c dynamicArray.cpp

testDynamicArray.o: testDynamicArray.cpp dynamicArray.h testDynamicArray.h
	$(CXX) $(CXXFLAGS) -c testDynamicArray.cpp

clean:
	rm -f *.o main
