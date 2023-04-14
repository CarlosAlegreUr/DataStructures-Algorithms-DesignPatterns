CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

all: main

main: main.o stack.o testStack.o
	$(CXX) $(CXXFLAGS) -o main main.o stack.o testStack.o

main.o: main.cpp stack.h testStack.h
	$(CXX) $(CXXFLAGS) -c main.cpp

stack.o: stack.cpp stack.h node.h
	$(CXX) $(CXXFLAGS) -c stack.cpp

testStack.o: testStack.cpp stack.h testStack.h
	$(CXX) $(CXXFLAGS) -c testStack.cpp

clean:
	rm -f *.o main
