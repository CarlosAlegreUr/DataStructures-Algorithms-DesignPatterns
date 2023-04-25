CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SOURCES = main.cpp hashTable.cpp testHashTable.cpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean run_tests

all: run_tests main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_tests: testHashTable.o hashTable.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	./run_tests

clean:
	rm -f $(OBJECTS) main run_tests
