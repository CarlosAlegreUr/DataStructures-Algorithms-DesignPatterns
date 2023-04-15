CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic

all: main

main: main.o queue.o testQueue.o
	$(CXX) $(CXXFLAGS) -o main main.o queue.o testQueue.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

queue.o: queue.cpp queue.h ../node.h
	$(CXX) $(CXXFLAGS) -c queue.cpp

testQueue.o: testQueue.cpp testQueue.h queue.h ../node.h
	$(CXX) $(CXXFLAGS) -c testQueue.cpp

.PHONY: clean
clean:
	rm -f main *.o
