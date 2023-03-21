# Merkle Tree Implementation in C++

This is a simple Merkle Tree implementation in C++ using the OpenSSL library for SHA-256 hashing.

## Dependencies

- OpenSSL (development package)

## Building and Running

To build the project, use the provided Makefile:

```sh
make
```

To run the tests and start the interactive prompt, execute the compiled binary:

```sh
./merkleTree
```

## Usage

Enter a transaction to check if it's in the Merkle Tree. Type 'exit' to quit the program.

```
Enter a transaction to check if it's in the Merkle Tree (type 'exit' to quit): Tx1
The transaction is in the Merkle Tree.
Enter another transaction (type 'exit' to quit): NonExistent
The transaction is not in the Merkle Tree.
Enter another transaction (type 'exit' to quit): exit
```
