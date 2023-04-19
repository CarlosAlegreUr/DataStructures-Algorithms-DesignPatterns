CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -g

all: main

main: main.o binaryTree.o testBinaryTree.o
	$(CC) $(CFLAGS) -o main main.o binaryTree.o testBinaryTree.o

main.o: main.cpp binaryTree.h testBinaryTree.h
	$(CC) $(CFLAGS) -c main.cpp

binaryTree.o: binaryTree.cpp binaryTree.h
	$(CC) $(CFLAGS) -c binaryTree.cpp

testBinaryTree.o: testBinaryTree.cpp testBinaryTree.h binaryTree.h
	$(CC) $(CFLAGS) -c testBinaryTree.cpp

clean:
	rm -f *.o main
