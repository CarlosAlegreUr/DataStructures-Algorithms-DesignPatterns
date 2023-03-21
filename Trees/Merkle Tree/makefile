CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lcrypto

OBJS = merkleTree.o main.o testMerkleTree.o

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) $(LDFLAGS)

MerkleTree.o: merkleTree.h merkleTree.cpp
	$(CXX) $(CXXFLAGS) -c merkleTree.cpp

main.o: main.cpp merkleTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

TestMerkleTree.o: testMerkleTree.cpp merkleTree.h
	$(CXX) $(CXXFLAGS) -c testMerkleTree.cpp

clean:
	rm -f main $(OBJS)
