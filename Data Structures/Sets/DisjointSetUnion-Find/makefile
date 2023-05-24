CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJS = main.o disjointSet.o testDisjointSet.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp disjointSet.h testDisjointSet.h
	$(CXX) $(CXXFLAGS) -c main.cpp

disjointSet.o: disjointSet.cpp disjointSet.h
	$(CXX) $(CXXFLAGS) -c disjointSet.cpp

testDisjointdisjointSet.o: testDisjointSet.cpp testDisjointSet.h disjointSet.h
	$(CXX) $(CXXFLAGS) -c testDisjointSet.cpp

clean:
	rm -f *.o main
