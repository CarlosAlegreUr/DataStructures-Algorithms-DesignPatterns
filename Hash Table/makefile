# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Object files
OBJS = main.o testHashTable.o

# Target executable
TARGET = main

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp hashTable.h testHashTable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

testHashTable.o: testHashTable.cpp testHashTable.h hashTable.h
	$(CXX) $(CXXFLAGS) -c testHashTable.cpp

clean:
	rm -f $(OBJS) $(TARGET)
