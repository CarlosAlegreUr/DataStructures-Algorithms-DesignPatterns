CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = main.cpp deque.cpp testDeque.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)
