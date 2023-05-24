CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJS = main.o set.o testSet.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp set.h testSet.h
	$(CXX) $(CXXFLAGS) -c main.cpp

set.o: set.cpp set.h
	$(CXX) $(CXXFLAGS) -c set.cpp

testSet.o: testSet.cpp testSet.h set.h
	$(CXX) $(CXXFLAGS) -c testSet.cpp

clean:
	rm -f *.o main
