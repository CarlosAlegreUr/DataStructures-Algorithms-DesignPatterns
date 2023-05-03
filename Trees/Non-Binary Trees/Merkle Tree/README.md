# Merkle Tree Implementation in C++

This is a simple Merkle Tree implementation in C++ using the OpenSSL library for SHA-256 hashing. There is also
a non finished function showing the algorithm to verify existance of data in the tree (verifyClient.cpp). 

Merkle Trees allow efficient and secure verification of large data sets. That is why they are mainly used in
in cryptocurrencies like Bitcoin to efficiently store and verify transactions in a block or in distributed file systems
like IPFS.

They also have good scalability though updating them (recalculating hashes) can be considered costly for large datasets.

The time cost of verification is O(log(n)).

## Dependencies

- OpenSSL (development package)

## Building and Running

To build the project, use the provided Makefile:

```sh
make
```

To run the tests and start the interactive prompt, execute the compiled binary:

```sh
./main
```
