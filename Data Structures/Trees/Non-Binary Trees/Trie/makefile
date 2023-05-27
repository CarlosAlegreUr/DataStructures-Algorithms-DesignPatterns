CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main: main.o trie.o testTrie.o
	$(CC) $(CFLAGS) -o main main.o trie.o testTrie.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

trie.o: trie.cpp
	$(CC) $(CFLAGS) -c trie.cpp

testTrie.o: testTrie.cpp
	$(CC) $(CFLAGS) -c testTrie.cpp

clean:
	rm -f *.o main
