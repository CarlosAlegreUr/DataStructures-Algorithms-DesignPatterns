CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS = -lcrypto
OUTPUT = merkleTree

all: $(OUTPUT)

$(OUTPUT): merkleTree.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
