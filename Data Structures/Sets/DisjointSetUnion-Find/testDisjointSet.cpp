#include "testDisjointSet.h"
#include "disjointSet.h"
#include <iostream>
#include <cassert>

void runTests() {
    // Create a DisjointSet with 5 elements
    DisjointSet ds(5);

    // Initially, all elements are in their own set.
    for (int i = 0; i < 5; i++) {
        assert(ds.find(i) == i);
    }

    // Union of sets
    ds.unionSets(0, 1);
    ds.unionSets(2, 3);
    ds.unionSets(3, 4);

    assert(ds.find(0) == ds.find(1));
    assert(ds.find(2) == ds.find(3));
    assert(ds.find(3) == ds.find(4));
    assert(ds.find(2) == ds.find(4));

    // Elements 0 and 1 are not in the same set as 2, 3, 4
    assert(ds.find(0) != ds.find(2));
    assert(ds.find(1) != ds.find(3));

    std::cout << "All tests passed.\n";
}
