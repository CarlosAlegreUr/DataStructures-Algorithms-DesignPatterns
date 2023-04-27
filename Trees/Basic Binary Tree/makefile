CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJS = main.o binaryTree.o testBinaryTree.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp binaryTree.h testBinaryTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

binaryTree.o: binaryTree.cpp binaryTree.h
	$(CXX) $(CXXFLAGS) -c binaryTree.cpp

testBinaryTree.o: testBinaryTree.cpp testBinaryTree.h binaryTree.h
	$(CXX) $(CXXFLAGS) -c testBinaryTree.cpp

clean:
	rm -f *.o main
