# Makefile
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

OBJS = main.o example.o
EXEC = main

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

example.o: example.cpp
	$(CXX) $(CXXFLAGS) -c example.cpp

clean:
	rm -f $(OBJS) $(EXEC)
